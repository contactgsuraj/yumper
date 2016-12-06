#include "Bob.hpp"
Bob::Bob(std::shared_ptr<Ball> bob1, std::shared_ptr<Ball> bob2,
         std::shared_ptr<Ball> bob3, std::shared_ptr<Ball> bob4) {
  this->bob1 = bob1;
  this->bob2 = bob2;
  this->bob3 = bob3;
  this->bob4 = bob4;
  bob_walking_frames[0] = bob1;
  bob_walking_frames[1] = bob2;
  bob_walking_frames[2] = bob3;
  bob_walking_frames[3] = bob2;
  bob_jumping_frames[0] = bob4;
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
    bob_jumping_frames[0]->render(
        20, bob_height - gravity.varGravityPositions[jump_counter], m_renderer);
    ++jump_counter;
    if (jump_counter >= gravity.m_max_frame) {
      jump_counter = 0;
      jump = false;
    }
  } else {
    (bob_walking_frames[bob_animation_counter / 10])
        ->render(20, bob_height, m_renderer);
  }
  // Bob counter
  bob_animation_counter++;
  bob_animation_counter %= 40;
}
