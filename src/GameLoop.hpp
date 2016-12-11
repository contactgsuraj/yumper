#ifndef gameLoop_H
#define gameLoop_H
#include <memory>
#include "SDL2/SDL.h"
#include "screen_objs/Bob.hpp"
#include "screen_objs/FPSCounter.hpp"
#include "screen_objs/TextureContainer.hpp"

class GameLoop {
 private:
  void clear(std::shared_ptr<Bob>, std::shared_ptr<TextureContainer>);
  std::shared_ptr<Timer> timer = std::make_shared<Timer>();
  std::shared_ptr<FPSCounter> fps_counter;
  void play(SDL_Renderer*& m_renderer);
  void loading_screen(SDL_Renderer*& m_renderer);
  std::shared_ptr<Bob> bob_c;
  std::shared_ptr<TextureContainer> t_container;

 public:
  bool run(SDL_Renderer*&);
  GameLoop(SDL_Renderer*&);
};

#endif /* game_loop_H */
