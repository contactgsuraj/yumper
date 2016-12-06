#ifndef IO_H
#define IO_H
#include "SDL2/SDL.h"
#include <memory>
#include "Bob.hpp"
#include "TextureContainer.hpp"

class IO
{
private:

public:
  void run(SDL_Renderer*&, std::shared_ptr<Bob>, std::shared_ptr<TextureContainer>);
};

#endif /* IO_H */
