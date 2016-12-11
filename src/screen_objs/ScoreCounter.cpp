#include "ScoreCounter.hpp"
#include <iomanip>
ScoreCounter::ScoreCounter() : Text() {
}

void ScoreCounter::count(SDL_Renderer*& m_renderer) {
  ++frame;
  if (frame == 5) {
    frame = 0;
    ++score;
  }
  render_fps(m_renderer);
  render(SCREEN_WIDTH - 195 , 10, m_renderer);
}

void ScoreCounter::render_fps(SDL_Renderer*& m_renderer) {
  std::stringstream ss;
  ss << "Score: " << std::setfill('0') << std::setw(7) << score;
  loadFont(ss.str(),  m_renderer, 36);
}

int ScoreCounter::getScore() {
  return score;
}
