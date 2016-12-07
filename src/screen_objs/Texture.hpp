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
  Texture();
  Texture(std::string path, SDL_Renderer*& renderer);
  Texture(bool is_font, std::string path, SDL_Renderer*& renderer);

  // Deallocates memory
  void clear();

  // Loads image at specified path
  bool loadFromFile(std::string path, SDL_Renderer*& renderer);
  //Renders Text
  void loadFont(std::string texture_text, SDL_Color text_color, SDL_Renderer*& m_renderer);

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
  TTF_Font* m_font = NULL;
};
#endif /* TEXTURE_H */
