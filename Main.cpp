#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <memory>
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

void close() {
  //// Destroy window
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  m_window = NULL;
  m_renderer = NULL;

  //// Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

int main(int argc, char* args[]) {
  /*Initialise windows*/
  if (!init(m_window, m_renderer)) {
    printf("Failed to initialize!\n");
    return 1;
  }

  // Textures
  std::shared_ptr<Ball> bob =
      std::make_shared<Ball>("assets/bob.png", m_renderer);
  std::shared_ptr<Ball> bob_2 =
      std::make_shared<Ball>("assets/bob3.png", m_renderer);
  std::shared_ptr<Ball> bob_3 =
      std::make_shared<Ball>("assets/bob2.png", m_renderer);
  std::shared_ptr<Ball> bob_4 =
      std::make_shared<Ball>("assets/bob4.png", m_renderer);
  std::shared_ptr<Texture> t_bg =
      std::make_shared<Texture>("assets/bg2.png", m_renderer);
  std::shared_ptr<Texture> t_floor =
      std::make_shared<Texture>("assets/floor.png", m_renderer);
  std::shared_ptr<Ball> bob_walking_frames[4] = {bob, bob_2, bob_3, bob_2};
  std::shared_ptr<Ball> bob_jumping_frames[2] = {bob, bob_4};

  bool quit = false;

  // Event handler
  SDL_Event e;

  // Initialise gravity, and calculate positions.
  Gravity gravity;

  // Initialise IO
  // IO io;

  /*TODO: Floor of BG!*/
  int height = (SCREEN_HEIGHT - 120) - 80 + 10;

  int bg_scroller_div = 5;
  int floor_scroller_div = 4;
  int bg_scroller_offset = 0;
  int floor_scroller_offset = 0;
  bool jump = false;
  int jump_counter = 0;
  int bob_animation_counter = 0;

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

    t_bg->render((-1 * bg_scroller_offset * bg_scroller_div), 0, m_renderer);
    t_floor->render((-1 * bg_scroller_offset * floor_scroller_div), (SCREEN_HEIGHT - 120), m_renderer);
    if (jump) {
      bob_jumping_frames[1]->render(
          20, height - gravity.varGravityPositions[jump_counter], m_renderer);
      ++jump_counter;
      if (jump_counter >= gravity.m_max_frame) {
        jump_counter = 0;
        jump = false;
      }
    } else {
      (bob_walking_frames[bob_animation_counter / 10])
          ->render(20, height, m_renderer);
    }

    // Update screen
    SDL_RenderPresent(m_renderer);
    bg_scroller_offset++;
    bg_scroller_offset %= (SCREEN_WIDTH / bg_scroller_div);
    floor_scroller_offset++;
    floor_scroller_offset %= (SCREEN_WIDTH / floor_scroller_div);

    // Bob counter
    bob_animation_counter++;
    bob_animation_counter %= 40;
  }

  // Free resources and close SDL
  close();
  bob->clear();
  bob_2->clear();
  bob_3->clear();
  t_bg->clear();
  t_floor->clear();

  return 0;
}
