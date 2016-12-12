#ifndef BOB_H
#define BOB_H
#include <memory>
#include <sstream>
#include <vector>
#include "../../const.hpp"
#include "../../physics/Gravity.hpp"
#include "Ball.hpp"

class Bob {
 private:
  int bob_animation_frames = 8;
  int shadow_blend = 130;
  int shadow_frames = 7;
  int shadow_frames_consolidated = shadow_frames * 2 - 1;
  int bob_animation_counter = 0;
  int jump_counter = 0;
  bool jump = false;
  int bob_dimension=150;
  int bob_height = (SCREEN_HEIGHT - 120) - bob_dimension + 10;
  int bob_shadow_width = 80;
  int bob_shadow_height = 20;
  Gravity gravity;
  std::vector<std::shared_ptr<Ball>> bobs_frames;
  std::vector<std::shared_ptr<Ball>> bobs_shadows;
  std::vector<std::shared_ptr<Ball>> ball_shadows;

 public:
  Bob(SDL_Renderer*& m_renderer);
  void run();
  void set_jump();
  void clear();
};

#endif /* BOB_H */
