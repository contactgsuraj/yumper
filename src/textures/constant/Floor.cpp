#include "Floor.hpp"
Floor::Floor(SDL_Renderer*& m_renderer) : ScrollableTexture(5, SCREEN_WIDTH, "assets/floor.png", m_renderer) {
  this->height = SCREEN_HEIGHT - 120;
}

int Floor::scrollCalculator() {
  return ScrollableTexture::scrollCalculator();
}
