#include "BG.hpp"
BG::BG(SDL_Renderer*& m_renderer) : ScrollableTexture(2, SCREEN_WIDTH*2, "assets/bg.png", m_renderer) {
  this->height = 0;
}

int BG::scrollCalculator() {
  ScrollableTexture::scrollCalculator();
}
