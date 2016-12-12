#include "Obstacle.hpp"
Obstacle::Obstacle(int difficulty, int scroller_div, int div_width, std::string asset, SDL_Renderer*& m_renderer) : ScrollableTexture (scroller_div, div_width, asset, m_renderer){
  this->difficulty = difficulty;
}

int Obstacle::getDifficulty() {
  return difficulty;
}
