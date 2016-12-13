#include "ObstacleGenerator.hpp"

ObstacleGenerator::ObstacleGenerator(SDL_Renderer*& m_renderer) {
  // link score of obstacle generator to scorecounter;
  nextobstacle = 5;
  this->spikes.push_back(std::make_shared<SpikeTrap>(m_renderer));
  this->spikes.push_back(std::make_shared<SpikeTrap>(m_renderer));
  this->spikes.push_back(std::make_shared<SpikeTrap>(m_renderer));
  this->spikes.push_back(std::make_shared<SpikeTrap>(m_renderer));
  this->spikes.push_back(std::make_shared<SpikeTrap>(m_renderer));
  this->spikes.push_back(std::make_shared<SpikeTrap>(m_renderer));
}

void ObstacleGenerator::run(int score) {
  // std::cerr << score << std::endl;
  if (score < 5) {
    return;
  }

  int mod1 = 6;
  int mod2 = 5;
  if (score < 30) {
    mod1 = 5;
    mod2 = 4;
  }
  if (score < 40) {
    mod1 = 3;
    mod2 = 4;
  }

  if (score < 50) {
    mod1 = 2;
    mod2 = 2;
  }

  if (nextobstacle == score) {
    std::cout << "Generating spikes" << std::endl;
    for (auto spike : spikes) {
      if (!spike->running) {
        spike->running = true;
        break;
      }
    }
    nextobstacle = (rand() % mod1 + mod2) + score;
    std::cout << "Generating next spike at " << nextobstacle << std::endl;
  }

  for (auto spike : spikes) {
    if (spike->running) {
      spike->run();
    }
  }
}
