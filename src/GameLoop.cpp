#include "GameLoop.hpp"

GameLoop::GameLoop(SDL_Renderer*& m_renderer) {
  timer->start();
  //fps_counter = std::make_shared<FPSCounter>(timer, m_renderer);
  bob_c = std::make_shared<Bob>(m_renderer);
  t_container = std::make_shared<TextureContainer>(m_renderer);
}

bool GameLoop::run(SDL_Renderer*& m_renderer) {
  static SDL_Event e;
  while (SDL_PollEvent(&e) != 0) {
    if (e.type == SDL_QUIT) {
      clear(bob_c, t_container);
      return true;
    } else if (e.type == SDL_KEYDOWN) {
      // Select surfaces based on key press
      switch (e.key.keysym.sym) {
        case SDLK_UP:
        case SDLK_SPACE:
          bob_c->set_jump();
          break;
        default:
          break;
      }
    }
  }

  // Clear screen
  SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(m_renderer);

  t_container->run(m_renderer);
  bob_c->run(m_renderer);
  //fps_counter->count(m_renderer);

  return false;
}

void GameLoop::clear(std::shared_ptr<Bob> bob_c, std::shared_ptr<TextureContainer> t_container) {
  bob_c->clear();
  t_container->clear();
}
