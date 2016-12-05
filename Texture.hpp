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

  // Gets image dimensions
  int getWidth();
  int getHeight();

 private:
  // The actual hardware texture
  SDL_Texture* mTexture;

  // Image dimensions
  int mWidth;
  int mHeight;
};
#endif /* TEXTURE_H */
