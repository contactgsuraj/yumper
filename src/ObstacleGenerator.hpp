#ifndef OBSTACLEGENERATOR_H
#define OBSTACLEGENERATOR_H
#include <cstdlib>
#include <vector>
#include <memory>
#include "textures/obstacles/spikeTrap/SpikeTrap.hpp"
#include "physics/Collision.hpp"
class ObstacleGenerator
{
public:
  ObstacleGenerator(SDL_Renderer*& m_renderer, std::shared_ptr<Collision>);
  void run(int score);
  void clear();
  void reset();
private:
  std::vector<std::shared_ptr<SpikeTrap>> spikes;
  int nextobstacle = 0;
};

#endif /* OBSTACLEGENERATOR_H */
