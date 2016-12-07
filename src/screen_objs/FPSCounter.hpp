#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H
#include <memory>
#include <sstream>
#include "../Timer.hpp"
#include "Texture.hpp"
#include "../const.hpp"
//#include <SDL2/SDL_ttf.h>
class FPSCounter : public Texture {
 private:
  int frame = 0;
  std::shared_ptr<Timer> m_timer;
  void render_fps(float, SDL_Renderer*&);
  SDL_Color text_color = { 0xeb, 0xdb, 0xb2 };
  float avg_fps = 0;
 public:
  FPSCounter(std::shared_ptr<Timer> timer, SDL_Renderer*& m_renderer);
  void count(SDL_Renderer*& m_renderer);
};

#endif /* FPSCOUNTER_H */
