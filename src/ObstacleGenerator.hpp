#ifndef OBSTACLEGENERATOR_H
#define OBSTACLEGENERATOR_H
#include <cstdlib>
#include <vector>
#include <memory>
#include "textures/obstacles/spikeTrap/SpikeTrap.hpp"
/* Score  | Obstacle generation algorithm
 * 5       Spikes generated every 10-15 score
 * 60
 * 
 * 
 * 
 * 
 * 
 * 
 * */
class ObstacleGenerator
{
public:
  ObstacleGenerator(SDL_Renderer*& m_renderer);
  void run(int score);
  void clear();
private:
  std::vector<std::shared_ptr<SpikeTrap>> spikes;
  int nextobstacle = 0;
};

#endif /* OBSTACLEGENERATOR_H */
