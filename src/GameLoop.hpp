#ifndef gameLoop_H
#define gameLoop_H
#include <memory>
#include "SDL2/SDL.h"
#include "ObstacleGenerator.hpp"
#include "textures/constant/Bob.hpp"
#include "textures/constant/FPSCounter.hpp"
#include "textures/constant/ScoreCounter.hpp"
#include "textures/constant/TextureContainer.hpp"
#include "textures/obstacles/spikeTrap/SpikeTrap.hpp"
#include "physics/Collision.hpp"

class GameLoop {
 private:
  bool is_dead;
  void clear();
  std::shared_ptr<Timer> timer = std::make_shared<Timer>();
  std::shared_ptr<ObstacleGenerator> og;
  std::shared_ptr<FPSCounter> fps_counter;
  std::shared_ptr<Text> pressSpace;
  std::shared_ptr<ScoreCounter> score;
  std::shared_ptr<Bob> bob_c;
  std::shared_ptr<TextureContainer> t_container;
  std::shared_ptr<Collision> collision;
  void play();
  void start_again();
  void loading_screen();
  bool start = false;
  bool IO();
  SDL_Renderer*& m_renderer;

 public:
  bool run();
  GameLoop(SDL_Renderer*&);
  void turnOnFPS();
  void dead();
};

#endif /* game_loop_H */
