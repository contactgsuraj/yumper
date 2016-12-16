#ifndef TEXTURECONTAINER_H
#define TEXTURECONTAINER_H
#include "../Texture.hpp"
#include "Floor.hpp"
#include "BG.hpp"
#include "../../const.hpp"
#include <memory>
#include <vector>

class TextureContainer {
 private:
  std::vector<std::shared_ptr<ScrollableTexture>> textures;
 public:
  TextureContainer(SDL_Renderer*& m_renderer);
  void clear();
  void run();
  void stop();
};

#endif /* TEXTURECONTAINER_H */
