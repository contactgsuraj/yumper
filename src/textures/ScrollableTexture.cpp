#include "ScrollableTexture.hpp"
ScrollableTexture::ScrollableTexture(int scroller_div, int div_width,std::string asset, SDL_Renderer*& m_renderer) : Texture(asset, m_renderer){
  this->scroller_div = scroller_div;
  this->div_width = div_width;
}

void ScrollableTexture::stop() {
  Texture::render(scrollCalculator(), height);
}

void ScrollableTexture::render() {
  Texture::render(scrollCalculator(), height);
  scroller_offset++;
  scroller_offset %= (div_width / scroller_div);
}
void ScrollableTexture::render(SDL_Rect* clip) {
  Texture::render(scrollCalculator(), height, clip);
  scroller_offset++;
  scroller_offset %= (div_width / scroller_div);
}

int ScrollableTexture::scrollCalculator() {
  return (-1 * scroller_offset * scroller_div);
}
