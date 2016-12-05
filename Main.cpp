#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "Texture.hpp"
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
  // Loading success flag
  bool success = true;

  // Load Foo' texture
  if (!t_bob.loadFromFile("assets/bob.png", m_renderer)) {
    printf("Failed to load Foo' texture image!\n");
    success = false;
  }

  // Load background texture
  if (!t_bg.loadFromFile("assets/bg.png", m_renderer)) {
    printf("Failed to load background texture image!\n");
    success = false;
  }

  return success;
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
  // Start up SDL and create window
  if (!init(m_window, m_renderer)) {
    printf("Failed to initialize!\n");
  } else {
    // Load media
    if (!loadMedia()) {
      printf("Failed to load media!\n");
    } else {
      // Main loop flag
      bool quit = false;

      // Event handler
      SDL_Event e;

      // While application is running
      while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
          // User requests quit
          if (e.type == SDL_QUIT) {
            quit = true;
          }
        }

        // Clear screen
        SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(m_renderer);

        // Render background texture to screen
        t_bg.render(0, 0, m_renderer);

        // Render Foo' to the screen
        t_bob.render(240, 190, m_renderer);

        // Update screen
        SDL_RenderPresent(m_renderer);
      }
    }
  }

  // Free resources and close SDL
  close();

  return 0;
}
