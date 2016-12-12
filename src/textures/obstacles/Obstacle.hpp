#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "../constant/Texture.hpp"

class Obstacle : public Texture
{
private:
  int difficulty;  
  int speed;
public:
  Obstacle(int difficulty, SDL_Renderer*& m_renderer);
  int getDifficulty();
};

#endif /* OBSTACLE_H */
