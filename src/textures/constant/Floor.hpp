#ifndef FLOOR_H
#define FLOOR_H
#include "../ScrollableTexture.hpp"
#include "../../const.hpp"

class Floor : public ScrollableTexture {
 private:
 protected:
   int scrollCalculator();
 public:
  Floor(SDL_Renderer*& m_renderer);
  void render();
};

#endif /* FLOOR_H */
