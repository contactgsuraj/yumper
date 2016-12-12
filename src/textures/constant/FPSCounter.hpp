#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H
#include <memory>
#include <sstream>
#include "../../Timer.hpp"
#include "../Text.hpp"
#include "../../const.hpp"
class FPSCounter : public Text {
 private:
  int frame = 0;
  std::shared_ptr<Timer> m_timer;
  void render_fps(float);
  SDL_Color text_color = { 0xeb, 0xdb, 0xb2 };
  float avg_fps = 0;
 public:
  FPSCounter(std::shared_ptr<Timer> timer, SDL_Renderer*& m_renderer);
  void count();
};

#endif /* FPSCOUNTER_H */
