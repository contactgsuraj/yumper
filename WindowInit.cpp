#include "WindowInit.hpp"
bool init(SDL_Window*& m_window, SDL_Renderer*& m_renderer) {
  // Initialization flag
  bool success = true;

  // Initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    success = false;
  } else {
    // Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
      printf("Warning: Linear texture filtering not enabled!");
    }

    // Create window
    m_window = SDL_CreateWindow("yumper", SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (m_window == NULL) {
      printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
      success = false;
    } else {
      // Create renderer for window
      m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (m_renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n",
               SDL_GetError());
        success = false;
      } else {
        // Initialize renderer color
        SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        // Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags)) {
          printf("SDL_image could not initialize! SDL_image Error: %s\n",
                 IMG_GetError());
          success = false;
        }
      }
    }
  }

  return success;
}
