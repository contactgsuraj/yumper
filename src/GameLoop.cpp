#include "GameLoop.hpp"

GameLoop::GameLoop(SDL_Renderer*& m_renderer) : m_renderer(m_renderer) {
  bob_c = std::make_shared<Bob>(m_renderer);
  t_container = std::make_shared<TextureContainer>(m_renderer);
  score = std::make_shared<ScoreCounter>(m_renderer);
  spikes = std::make_shared<SpikeTrap>(m_renderer);
}

bool GameLoop::run() {
  if (IO()) {
    return true;
  }
  SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(m_renderer);

  t_container->run();
  bob_c->run();

  /*call turnOnFPS() to enable FPS counter*/
  if (fps_counter) {
    fps_counter->count();
  }

  if (!start) {
    loading_screen();
  } else {
    spikes->run();
    play();
  }

  return false;
}

void GameLoop::clear() {
  bob_c->clear();
  t_container->clear();
  pressSpace->clear();
  score->clear();
  spikes->clear();
  if (fps_counter) {
    fps_counter->clear();
  }
}

void GameLoop::play(){
  score->count();
}

void GameLoop::loading_screen() {
  if (!pressSpace) {
    pressSpace = std::make_shared<Text>("Press Space To Start", 64, m_renderer);
  }
  pressSpace->render((SCREEN_WIDTH - pressSpace->get_width()) / 2, 10);
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
      bob_c->set_jump();
    }
  }
  return false;
}
