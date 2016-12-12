#include "Obstacle.hpp"
Obstacle::Obstacle(int difficulty, SDL_Renderer*& m_renderer) : Texture(m_renderer) {
  this->difficulty = difficulty;
}

int Obstacle::getDifficulty() {
  return difficulty;
}
