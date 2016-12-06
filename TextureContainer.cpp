#include "TextureContainer.hpp"

TextureContainer::TextureContainer(SDL_Renderer*& m_renderer) {
  textures.push_back(std::make_shared<Texture>("assets/bg2.png", m_renderer));
  textures.push_back(std::make_shared<Texture>("assets/floor.png", m_renderer));
}

void TextureContainer::clear() {
  for (auto tex : textures) {
    tex->clear();
  }
}

void TextureContainer::run(SDL_Renderer*& m_renderer) {
  textures[0]->render((-1 * bg_scroller_offset * bg_scroller_div), 0,
                      m_renderer);
  textures[1]->render((-1 * bg_scroller_offset * floor_scroller_div),
                      (SCREEN_HEIGHT - 120), m_renderer);

  bg_scroller_offset++;
  bg_scroller_offset %= (SCREEN_WIDTH / bg_scroller_div);
  floor_scroller_offset++;
  floor_scroller_offset %= (SCREEN_WIDTH / floor_scroller_div);
}
