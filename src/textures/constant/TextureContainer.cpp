#include "TextureContainer.hpp"

TextureContainer::TextureContainer(SDL_Renderer*& m_renderer) {
  textures.push_back(std::make_shared<BG>(m_renderer));
  textures.push_back(std::make_shared<Floor>(m_renderer));
}

void TextureContainer::clear() {
  for (auto tex : textures) {
    if (tex) {
      tex->clear();
    }
  }
}

void TextureContainer::run() {
  textures[0]->render();
  textures[1]->render();
}

void TextureContainer::stop() {
  textures[0]->stop();
  textures[1]->stop();
}
