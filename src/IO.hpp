#ifndef IO_H
#define IO_H
#include <memory>
#include "SDL2/SDL.h"
#include "screen_objs/Bob.hpp"
#include "screen_objs/FPSCounter.hpp"
#include "screen_objs/TextureContainer.hpp"

class IO {
 private:
  void clear(std::shared_ptr<Bob>, std::shared_ptr<TextureContainer>);
  std::shared_ptr<Timer> timer = std::make_shared<Timer>();
  std::shared_ptr<FPSCounter> fps_counter;

 public:
  bool run(SDL_Renderer*&, std::shared_ptr<Bob>, std::shared_ptr<TextureContainer>);
  IO(SDL_Renderer*&);
};

#endif /* IO_H */
