#ifndef BOB_H
#define BOB_H
#include "Ball.hpp"
#include "const.hpp"
#include "Gravity.hpp"
#include <memory>

class Bob {
 private:
  int bob_animation_counter = 0;
  int jump_counter = 0;
  bool jump = false;
  int bob_height = (SCREEN_HEIGHT - 120) - 80 + 10;
  std::shared_ptr<Ball> bob1;
  std::shared_ptr<Ball> bob2;
  std::shared_ptr<Ball> bob3;
  std::shared_ptr<Ball> bob4;
  std::shared_ptr<Ball> bob_walking_frames[4];
  std::shared_ptr<Ball> bob_jumping_frames[2];
  Gravity gravity;
  public:
  Bob(std::shared_ptr<Ball>, std::shared_ptr<Ball>, std::shared_ptr<Ball>,
      std::shared_ptr<Ball>);
  void run(SDL_Renderer*& m_renderer);
  void set_jump();
};

#endif /* BOB_H */
