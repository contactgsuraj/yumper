#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "../ScrollableTexture.hpp"

class Obstacle : public ScrollableTexture
{
private:
  int difficulty;  
  int speed;
public:
  Obstacle(int difficulty, int scroller_div, int div_width, std::string asset, SDL_Renderer*& m_renderer);
  int getDifficulty();
};

#endif /* OBSTACLE_H */
