#ifndef SCORECOUNTER_H
#define SCORECOUNTER_H
#include <memory>
#include <sstream>
#include "../Timer.hpp"
#include "../const.hpp"
#include "Text.hpp"
class ScoreCounter : public Text {
 private:
  int frame = 0;
  int score = 0;
  void render_fps(SDL_Renderer*&);
  SDL_Color text_color = { 0x28, 0x28, 0x28 };
  int text_width;
 public:
  ScoreCounter();
  void count(SDL_Renderer*& m_renderer);
  int getScore();
};

#endif /* SCORECOUNTER_H */
