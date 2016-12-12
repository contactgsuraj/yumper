#include "Obstacle.hpp"
Obstacle::Obstacle(int difficulty) {
  this->difficulty = difficulty;
}

int Obstacle::getDifficulty() {
  return difficulty;
}
