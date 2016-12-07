#include "FPSCounter.hpp"

FPSCounter::FPSCounter(std::shared_ptr<Timer> timer, SDL_Renderer*& renderer)
    : Text() {
  m_timer = timer;
}

void FPSCounter::count(SDL_Renderer*& m_renderer) {
  avg_fps = frame / (m_timer->get_ticks() / 1000.f);
  if (avg_fps > 2000) {
    avg_fps = 0;
  }
  if (frame >= 1000000 || m_timer->get_ticks() > 3000000) {
    m_timer->stop();
    m_timer->start();
    frame = 0;
  }
  ++frame;
  render_fps(avg_fps, m_renderer);
}

void FPSCounter::render_fps(float avg_fps, SDL_Renderer*& m_renderer) {
  std::stringstream ss;
  ss << (int)avg_fps << " FPS";
  loadFont(ss.str(), text_color, m_renderer);
}
