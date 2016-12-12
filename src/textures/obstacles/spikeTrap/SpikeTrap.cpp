#include "SpikeTrap.hpp"
SpikeTrap::SpikeTrap(SDL_Renderer*& m_renderer) : Obstacle(1, 5, SCREEN_WIDTH, "assets/spikes/spikes.png",  m_renderer) {
  this->height = SCREEN_HEIGHT - 211;
}

void SpikeTrap::run() {
  SDL_Rect clip;
  clip.w = 128;
  clip.h = 120;
  clip.x = (spike_frames_counter / 2) * clip.w;
  clip.y = 0;
  render(&clip);
  if (spike_frames_counter <= 8) {
    ++spike_frames_counter;
  }
}

int SpikeTrap::scrollCalculator() {
  return SCREEN_WIDTH - this->get_width() / 5 - (scroller_offset * scroller_div);
}
