#ifndef TEXTURECONTAINER_H
#define TEXTURECONTAINER_H
#include "Texture.hpp"
#include "../../const.hpp"
#include <memory>
#include <vector>

class TextureContainer {
 private:
  SDL_Renderer*& m_renderer;
  const int BG_WIDTH = 980 * 2;
  std::vector<std::shared_ptr<Texture>> textures;
  const int bg_scroller_div = 2;
  const int floor_scroller_div = 5;
  int bg_scroller_offset = 0;
  int floor_scroller_offset = 0;
 public:
  TextureContainer(SDL_Renderer*& m_renderer);
  void clear();
  void run();
};

#endif /* TEXTURECONTAINER_H */
