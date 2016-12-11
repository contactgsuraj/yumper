#include "TextureContainer.hpp"

TextureContainer::TextureContainer(SDL_Renderer*& m_renderer) {
  textures.push_back(std::make_shared<Texture>("assets/bg3.png", m_renderer));
  textures.push_back(std::make_shared<Texture>("assets/floor2.png", m_renderer));
}

void TextureContainer::clear() {
  for (auto tex : textures) {
    if (tex) {
      tex->clear();
    }
  }
}

void TextureContainer::run(SDL_Renderer*& m_renderer) {
  // const int bg_scroller_div = 3;
  // int bg_scroller_offset = 0;
  textures[0]->render((-1 * bg_scroller_offset * bg_scroller_div), 0, m_renderer);
  // textures[0]->render((-1 * bg_scroller_offset), 0, m_renderer);
  textures[1]->render((-1 * floor_scroller_offset * floor_scroller_div), (SCREEN_HEIGHT - 120), m_renderer);
  bg_scroller_offset++;
  bg_scroller_offset %= (BG_WIDTH / bg_scroller_div);
  floor_scroller_offset++;
  floor_scroller_offset %= (SCREEN_WIDTH / floor_scroller_div);
}
