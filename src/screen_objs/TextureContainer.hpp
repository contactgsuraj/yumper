#ifndef TEXTURECONTAINER_H
#define TEXTURECONTAINER_H
#include "Texture.hpp"
#include "../const.hpp"
#include <memory>
#include <vector>

class TextureContainer {
 private:
  //std::shared_ptr<Texture> t_bg;
  //std::shared_ptr<Texture> t_floor;
  std::vector<std::shared_ptr<Texture>> textures;
  const int bg_scroller_div = 3;
  const int floor_scroller_div = 6;
  int bg_scroller_offset = 0;
  int floor_scroller_offset = 0;
 public:
  TextureContainer(SDL_Renderer*& m_renderer);
  void clear();
  void run(SDL_Renderer*& m_renderer);
};

#endif /* TEXTURECONTAINER_H */
