#ifndef gameLoop_H
#define gameLoop_H
#include <memory>
#include "SDL2/SDL.h"
#include "screen_objs/Bob.hpp"
#include "screen_objs/FPSCounter.hpp"
#include "screen_objs/ScoreCounter.hpp"
#include "screen_objs/TextureContainer.hpp"

class GameLoop {
 private:
  void clear();
  std::shared_ptr<Timer> timer = std::make_shared<Timer>();
  std::shared_ptr<FPSCounter> fps_counter;
  std::shared_ptr<Text> pressSpace;
  std::shared_ptr<ScoreCounter> score;
  std::shared_ptr<Bob> bob_c;
  std::shared_ptr<TextureContainer> t_container;
  void play();
  void loading_screen();
  bool start = false;
  bool IO();
  SDL_Renderer*& m_renderer;

 public:
  bool run();
  GameLoop(SDL_Renderer*&);
  void turnOnFPS();
};

#endif /* game_loop_H */
