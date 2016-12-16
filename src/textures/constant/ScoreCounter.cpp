#include "ScoreCounter.hpp"
#include <iomanip>
ScoreCounter::ScoreCounter(SDL_Renderer*& m_renderer) : Text(m_renderer) {
}

void ScoreCounter::count() {
  ++frame;
  if (frame == 30) {
    frame = 0;
    ++score;
  }
  render_fps();
  render(SCREEN_WIDTH - 195, 10);
}

void ScoreCounter::render_fps() {
  std::stringstream ss;
  ss << "Score: " << std::setfill('0') << std::setw(7) << score;
  loadFont(ss.str(), 36);
}

int ScoreCounter::getScore() {
  return score;
}

void ScoreCounter::reset() {
  score = 0;
}
