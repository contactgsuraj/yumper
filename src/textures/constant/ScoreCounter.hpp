#ifndef SCORECOUNTER_H
#define SCORECOUNTER_H
#include <memory>
#include <sstream>
#include "../../const.hpp"
#include "../Text.hpp"
class ScoreCounter : public Text {
 private:
  int frame = 0;
  int score = 0;
  void render_fps();
  SDL_Color text_color = { 0x28, 0x28, 0x28 };
  int text_width;
 public:
  ScoreCounter(SDL_Renderer*& m_renderer);
  void count();
  int getScore();
};

#endif /* SCORECOUNTER_H */
