#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "Ball.hpp"
#include "Gravity.hpp"
#include "IO.hpp"
#include "Texture.hpp"
#include "Timer.hpp"
#include "WindowInit.hpp"

// Frees media and shuts down SDL
void close();

// The window we'll be rendering to
SDL_Window* m_window = NULL;
SDL_Window& windowRef = *m_window;

// The window renderer
SDL_Renderer* m_renderer = NULL;
SDL_Renderer& rendererRef = *m_renderer;

// Scene textures
Ball* t_bob = NULL;
Texture* t_bg = NULL;

void close() {
  // Free loaded images
  t_bob->free();
  t_bg->free();

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

  Ball t_bob("assets/bob.png", m_renderer);
  Texture t_bg("assets/bg2.png", m_renderer);

  bool quit = false;

  // Event handler
  SDL_Event e;

  // Initialise gravity, and calculate positions.
  Gravity gravity;

  // Initialise IO
  // IO io;

  /*TODO: Floor of BG!*/
  int height = 340;

  int bg_scroller_offset = 0;
  bool jump = false;
  int jump_counter = 0;

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
            jump = true;
            if (jump_counter) {
              ++jump_counter;
            }
            break;
          default:
            break;
        }
      }
    }
    // Clear screen
    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(m_renderer);

    t_bg.render((-1 * bg_scroller_offset * 5), 0, m_renderer);
    if (jump) {
      t_bob.render(20, height - gravity.varGravityPositions[jump_counter],
                   m_renderer);
      ++jump_counter;
      if (jump_counter >= gravity.m_max_frame) {
        jump_counter = 0;
        jump = false;
      }
    } else {
      t_bob.render(20, height, m_renderer);
    }

    // Update screen
    SDL_RenderPresent(m_renderer);
    bg_scroller_offset++;
    bg_scroller_offset %= (SCREEN_WIDTH / 5);
  }

  // Free resources and close SDL
  close();

  return 0;
}
