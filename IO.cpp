#include "IO.hpp"
void IO::run(SDL_Renderer*& m_renderer, std::shared_ptr<Bob> bob_c, std::shared_ptr<TextureContainer> t_container) {
  bool quit = false;
  SDL_Event e;
  while (!quit) {
    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = true;
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

    // Update screen
    SDL_RenderPresent(m_renderer);
  }
}
