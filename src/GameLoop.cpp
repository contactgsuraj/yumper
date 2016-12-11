#include "GameLoop.hpp"

GameLoop::GameLoop(SDL_Renderer*& m_renderer) : m_renderer(m_renderer) {
  bob_c = std::make_shared<Bob>(m_renderer);
  t_container = std::make_shared<TextureContainer>(m_renderer);
}

bool GameLoop::run() {
  if (IO()) {
    return true;
  }
  SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(m_renderer);

  t_container->run(m_renderer);
  bob_c->run(m_renderer);

  /*call turnOnFPS() to enable FPS counter*/
  if (fps_counter) {
    fps_counter->count(m_renderer);
  }

  if (!start) {
    loading_screen();
  } else {
    play();
  }

  return false;
}

void GameLoop::clear() {
  bob_c->clear();
  t_container->clear();
  pressSpace->clear();
  score->clear();
  if (fps_counter) {
    fps_counter->clear();
  }
}

void GameLoop::play(){
  if (!score) {
    score = std::make_shared<ScoreCounter>();
  }
  score->count(m_renderer);
}

void GameLoop::loading_screen() {
  if (!pressSpace) {
    pressSpace = std::make_shared<Text>("Press Space To Start", 64, m_renderer);
  }
  pressSpace->render((SCREEN_WIDTH - pressSpace->get_width()) / 2, 10, m_renderer);
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
