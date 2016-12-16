#ifndef SPIKETRAP_H
#define SPIKETRAP_H
#include <SDL2/SDL.h>
#include "../Obstacle.hpp"
#include "../../../const.hpp"
#include "../../../physics/Collision.hpp"

class SpikeTrap : public Obstacle
{
private:
  int spike_frames_counter = 0;
  //collision = std::make_shared<Collision>(bob_c);
  std::shared_ptr<Collision> collision;
protected:
  int scrollCalculator();
public:
  int x;
  SpikeTrap(SDL_Renderer*&, std::shared_ptr<Collision> collision);
  void run();
  void runhelper();
  void resetSpikes();
  bool running = false;
};


#endif /* SPIKETRAP_H */
