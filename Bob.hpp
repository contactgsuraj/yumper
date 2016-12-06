#ifndef BOB_H
#define BOB_H
#include "Ball.hpp"
#include "const.hpp"
#include "Gravity.hpp"
#include <memory>
#include <vector>

class Bob {
 private:
  int bob_animation_counter = 0;
  int jump_counter = 0;
  bool jump = false;
  int bob_height = (SCREEN_HEIGHT - 120) - 80 + 10;
  Gravity gravity;
  std::vector<std::shared_ptr<Ball>> bobs_balls;

  public:
  Bob(SDL_Renderer*& m_renderer);
  void run(SDL_Renderer*& m_renderer);
  void set_jump();
  void clear();
};

#endif /* BOB_H */
