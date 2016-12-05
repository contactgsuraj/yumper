#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

class Texture {
 public:
  // Initializes variables
  Texture();

  // Deallocates memory
  ~Texture();

  // Loads image at specified path
  bool loadFromFile(std::string path, SDL_Renderer*& renderer);

  // Deallocates texture
  void free();

  // Renders texture at given point
  void render(int x, int y, SDL_Renderer*&);

  // Renders with a clipping
  void render(int x, int y, SDL_Rect* clip, SDL_Renderer*&);

  // Gets image dimensions
  int get_width();
  int get_height();

 private:
  SDL_Texture* mTexture;
  int m_width;
  int m_height;
};
#endif /* TEXTURE_H */
