#ifndef COLLISION_H
#define COLLISION_H
#include <memory>
#include "../textures/constant/Bob.hpp"
class Collision
{
private:
  std::shared_ptr<Bob> bob_c; 
  int easy_mode = 10;
public:
  Collision(std::shared_ptr<Bob>);
  void spike_detect();
};

#endif /* COLLISION_H */
