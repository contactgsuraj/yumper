#ifndef TEXT_H
#define TEXT_H
#include "Texture.hpp"

class Text : public Texture {
 private:
  TTF_Font* m_font = NULL;
  SDL_Color default_bg = {0x7d, 0x7d, 0x7d};
  SDL_Color default_text_color = {0x28, 0x28, 0x28};

 public:
  // Renders Text
  Text(SDL_Renderer*& m_renderer);
  Text(std::string text, int size, SDL_Renderer*& m_renderer);
  Text(std::string text, int size, SDL_Renderer*& m_renderer,SDL_Color bg);
  void loadFont(std::string texture_text, int size);
  void loadFont(std::string texture_text, SDL_Color text_color);
  void loadFont(std::string texture_text, int size, SDL_Color text_color, SDL_Color bg);
  void clear();
};

#endif /* TEXT_H */
