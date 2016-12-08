#include "Bob.hpp"
Bob::Bob(SDL_Renderer*& m_renderer) {
  for (int i = 1; i <= bob_animation_frames; ++i) {
    bobs_balls.push_back(std::make_shared<Ball>("assets/bob" + std::to_string(i) + ".png", m_renderer));
  }
  bobs_shadows.push_back(std::make_shared<Ball>("assets/shadow1.png", m_renderer));
  for (int i = 0; i <= shadow_frames + 1; ++i) {
    //std::cerr << i << std::endl;
    if (i!=0) {
      ball_shadows.push_back(std::make_shared<Ball>("assets/shadow" + std::to_string(i) + ".png", m_renderer));
      bobs_shadows.push_back(ball_shadows[i - 1]);
    }
    bobs_shadows[i]->set_blend_mode(SDL_BLENDMODE_BLEND);
    bobs_shadows[i]->set_alpha(shadow_blend);
  }
  //bobs_shadows[0]->set_blend_mode(SDL_BLENDMODE_BLEND);
  //bobs_shadows[0]->set_alpha(shadow_blend);
  for (int i = shadow_frames - 1; i >= 0; --i) {
    bobs_shadows.push_back(ball_shadows[i]);
  }
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
    float grav_pos = gravity.varGravityPositions[jump_counter];
    bobs_shadows[(jump_counter / ((gravity.m_max_frame + 1) / shadow_frames_consolidated))]->render(20, bob_height + 73,
                                                                                                    m_renderer);
    bobs_balls[bob_animation_counter / 5]->render(20, bob_height - gravity.varGravityPositions[jump_counter],
                                                  m_renderer);
    ++jump_counter;
    if (jump_counter >= gravity.m_max_frame) {
      jump_counter = 0;
      jump = false;
    }
  } else {
    bobs_shadows[0]->render(20, bob_height + 73, m_renderer);
    bobs_balls[bob_animation_counter / 5]->render(20, bob_height, m_renderer);
  }
  // Bob counter
  bob_animation_counter++;
  bob_animation_counter %= 40;
}

void Bob::clear() {
  for (auto ball : bobs_balls) {
    if (ball) {
      ball->clear();
    }
  }
}
