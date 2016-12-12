#ifndef SPIKETRAP_H
#define SPIKETRAP_H
#include <SDL2/SDL.h>
#include "../Obstacle.hpp"

class SpikeTrap : public Obstacle
{
private:

public:
  SpikeTrap(SDL_Renderer*&);
  void run();
};

#endif /* SPIKETRAP_H */
