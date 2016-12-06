#ifndef IO_H
#define IO_H
#include "SDL2/SDL.h"
#include <memory>
#include "screen_objs/Bob.hpp"
#include "screen_objs/TextureContainer.hpp"

class IO
{
private:
  void close(std::shared_ptr<Bob>, std::shared_ptr<TextureContainer>);
public:
  void run(SDL_Renderer*&, std::shared_ptr<Bob>, std::shared_ptr<TextureContainer>);
};

#endif /* IO_H */
