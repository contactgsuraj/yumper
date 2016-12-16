#include "ObstacleGenerator.hpp"
ObstacleGenerator::ObstacleGenerator(SDL_Renderer*& m_renderer, std::shared_ptr<Collision> collision) {
  // link score of obstacle generator to scorecounter;
  nextobstacle = 5;
  for (int i = 0; i < 8; ++i) {
    spikes.push_back(std::make_shared<SpikeTrap>(m_renderer, collision));
  }
}

void ObstacleGenerator::run(int score) {
  // std::cerr << score << std::endl;
  srand (time(NULL));
  if (score < 5) {
    return;
  }

  int mod1 = 3;
  int mod2 = 3;
  //if (score > 50) {
  //  mod1 = 5; 
  //  mod2 = 5;
  //} else if (score > 100) {
  //  mod1 = 5; 
  //  mod2 = 4;
  //} else if (score > 130) {
  //  mod1 = 4; 
  //  mod2 = 4;
  //} else if (score > 170) {
  //  mod1 = 3; 
  //  mod2 = 3;
  //}

  if (nextobstacle == score) {
//    std::cout << "Generating spikes" << std::endl;
    for (auto spike : spikes) {
      if (!spike->running) {
        spike->running = true;
        break;
      }
    }
    nextobstacle = (rand() % mod1 + mod2) + score;
    //std::cout << "Generating next spike at " << nextobstacle << std::endl;
  }

  for (auto spike : spikes) {
    if (spike->running) {
      spike->run();
    }
  }
}
void ObstacleGenerator::clear() {
  for (auto spike : spikes) {
    spike->clear();
  }
}

void ObstacleGenerator::reset() {
  nextobstacle = 5;
  for (auto spike : spikes) {
    spike->running = false; 
    spike->resetSpikes();
  }
}
