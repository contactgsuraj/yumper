#ifndef SPIKETRAP_H
#define SPIKETRAP_H
#include <SDL2/SDL.h>
#include "../Obstacle.hpp"
#include "../../../const.hpp"

class SpikeTrap : public Obstacle
{
private:
  int spike_frames_counter = 0;
protected:
  int scrollCalculator();
public:
  SpikeTrap(SDL_Renderer*&);
  void run();
};

#endif /* SPIKETRAP_H */
