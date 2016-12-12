#ifndef SCROLLABLETEXTURE_H
#define SCROLLABLETEXTURE_H
#include "Texture.hpp"

class ScrollableTexture : public Texture
{
private:
protected:
  virtual int scrollCalculator() = 0;
  int scroller_offset = 0;
  int scroller_div = 0;
  int div_width;
  int location;
  int height;
public:
  ScrollableTexture(int scroller_div, int div_width, std::string asset, SDL_Renderer*& m_renderer);
  void render();
  void render(SDL_Rect* clip);
};

#endif /* SCROLLABLETEXTURE_H */
