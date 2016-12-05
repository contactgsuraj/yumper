#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "Texture.hpp"
#include "Timer.hpp"
#include "WindowInit.hpp"

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

// The window we'll be rendering to
SDL_Window* m_window = NULL;
SDL_Window& windowRef = *m_window;

// The window renderer
SDL_Renderer* m_renderer = NULL;
SDL_Renderer& rendererRef = *m_renderer;

// Scene textures
Texture t_bob;
Texture t_bg;

bool loadMedia() {
  // Load Foo' texture
  if (!t_bob.loadFromFile("assets/bob.png", m_renderer)) {
    printf("Failed to load Foo' texture image!\n");
    return false;
  }

  // Load background texture
  if (!t_bg.loadFromFile("assets/bg.png", m_renderer)) {
    printf("Failed to load background texture image!\n");
    return false;
  }

  return true;
}

void close() {
  // Free loaded images
  t_bob.free();
  t_bg.free();

  // Destroy window
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  m_window = NULL;
  m_renderer = NULL;

  // Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

int main(int argc, char* args[]) {
  if (!init(m_window, m_renderer)) {
    printf("Failed to initialize!\n");
    return 1;
  }

  if (!loadMedia()) {
    printf("Failed to load media!\n");
    return 1;
  }

  bool quit = false;

  // Event handler
  SDL_Event e;

  int height = 340;
  Timer timer;
  int counter = 0;
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
            height = 240;
            break;
          default:
            height = 340;
            break;
        }
      }
    }
    // Clear screen
    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(m_renderer);

    t_bg.render((-1 * counter * 4), 0,  m_renderer);
    //t_bob.render(20, height, m_renderer);

    // Update screen
    SDL_RenderPresent(m_renderer);
    counter++;
    counter %= 160;
  }

  // Free resources and close SDL
  close();

  return 0;
}
