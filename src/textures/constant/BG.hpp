#ifndef BG_H
#define BG_H
#include "../ScrollableTexture.hpp"
#include "../../const.hpp"
class BG : public ScrollableTexture {
 private:
 protected:
   int scrollCalculator();
 public:
  BG(SDL_Renderer*& m_renderer);
};

#endif /* BG_H */
