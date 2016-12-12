#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

class Texture {
 public:
  // Initializes variables
  Texture(SDL_Renderer*&);
  Texture(std::string path, SDL_Renderer*& renderer);

  void clear();

  // Loads image at specified path
  bool loadFromFile(std::string path);

  // Renders texture at given point
  void render(int x, int y);

  // Renders with a clipping
  void render(int x, int y, SDL_Rect* clip);

  // Transparency
  void set_blend_mode(SDL_BlendMode blending);
  void set_alpha(Uint8 alpha);

  // Gets image dimensions
  int get_width();
  int get_height();

 protected:
  SDL_Texture* mTexture;
  int m_width;
  int m_height;
  SDL_Renderer*& m_renderer;

 private:
  // TTF_Font* m_font = NULL;
};
#endif /* TEXTURE_H */
