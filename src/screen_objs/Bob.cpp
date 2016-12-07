#include "Bob.hpp"
Bob::Bob(SDL_Renderer*& m_renderer) {
  bobs_balls.push_back(std::make_shared<Ball>("assets/bob.png", m_renderer));
  bobs_balls.push_back(std::make_shared<Ball>("assets/bob3.png", m_renderer));
  bobs_balls.push_back(std::make_shared<Ball>("assets/bob2.png", m_renderer));
  bobs_shadow = std::make_shared<Ball>("assets/shadow.png", m_renderer);
  //bobs_balls.push_back(std::make_shared<Ball>("assets/bob4.png", m_renderer));
  this->gravity.process();
}

void Bob::set_jump() {
  jump = true;
  if (jump_counter) {
    ++jump_counter;
  }
}

void Bob::run(SDL_Renderer*& m_renderer) {
  if (jump) {
    bobs_balls[0]->render(
        20, bob_height - gravity.varGravityPositions[jump_counter], m_renderer);
    ++jump_counter;
    if (jump_counter >= gravity.m_max_frame) {
      jump_counter = 0;
      jump = false;
    }
  } else {
    (bobs_balls[bob_animation_counter / 10])
        ->render(20, bob_height, m_renderer);
  }
  // Bob counter
  bob_animation_counter++;
  bob_animation_counter %= 20;
}

void Bob::clear() {
  for (auto ball : bobs_balls) {
    if (ball) {
      ball->clear();
    }
  }
}
