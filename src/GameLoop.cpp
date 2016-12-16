#include "GameLoop.hpp"

GameLoop::GameLoop(SDL_Renderer*& m_renderer) : m_renderer(m_renderer) {
  bob_c = std::make_shared<Bob>(m_renderer);
  t_container = std::make_shared<TextureContainer>(m_renderer);
  score = std::make_shared<ScoreCounter>(m_renderer);
  collision = std::make_shared<Collision>(bob_c);
  og = std::make_shared<ObstacleGenerator>(m_renderer, collision);
}

bool GameLoop::run() {
  if (IO()) {
    return true;
  }
  SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(m_renderer);

  /*call turnOnFPS() to enable FPS counter*/
  if (bob_c->is_dead) {
    is_dead = true;
    dead();
  } else {
    if (!start) {
      loading_screen();
    } else {
      play();
    }
  }

  if (fps_counter) {
    fps_counter->count();
  }

  return false;
}

void GameLoop::clear() {
  bob_c->clear();
  t_container->clear();
  pressSpace->clear();
  score->clear();
  // spikes->clear();
  if (fps_counter) {
    fps_counter->clear();
  }
  og->clear();
}

void GameLoop::play() {
  t_container->run();
  bob_c->run();
  score->count();
  og->run(score->getScore());
  // ObstacleGeneration->run(&score->getScore());
}
void GameLoop::dead() {
  // std::cout << "ur ded" << std::endl;
  Texture died = Texture("assets/die.png", m_renderer);
  t_container->stop();
  died.render(0, 0);
  SDL_Color bg = {0xef, 0x4e, 0x4e};
  auto deathText = Text("You Died, Press Space To Start", 64, m_renderer, bg);
  deathText.render((SCREEN_WIDTH - deathText.get_width()) / 2, 10);
}

void GameLoop::loading_screen() {
  t_container->run();
  if (!pressSpace) {
    pressSpace = std::make_shared<Text>("Press Space To Start", 64, m_renderer);
  }
  pressSpace->render((SCREEN_WIDTH - pressSpace->get_width()) / 2, 10);
  bob_c->run();
}

void GameLoop::turnOnFPS() {
  timer->start();
  fps_counter = std::make_shared<FPSCounter>(timer, m_renderer);
}

bool GameLoop::IO() {
  static SDL_Event e;
  while (SDL_PollEvent(&e) != 0) {
    if (e.type == SDL_QUIT) {
      clear();
      return true;
    }
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_SPACE] || currentKeyStates[SDL_SCANCODE_W]) {
      if (!start) {
        start = true;
      }
      if (bob_c->is_dead) {
        bob_c->is_dead = false;
        start_again();
      } else {
        bob_c->set_jump();
      }
    }
  }
  return false;
}

void GameLoop::start_again() {
  //Score returns to 0;
  // og resets next obstacle to 5
  score->reset();
  og->reset();
  start = false;
}
