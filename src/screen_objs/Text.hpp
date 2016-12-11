#ifndef TEXT_H
#define TEXT_H
#include "Texture.hpp"

class Text : public Texture {
 private:
  TTF_Font* m_font = NULL;
  SDL_Color default_text_color = {0x28, 0x28, 0x28};

 public:
  // Renders Text
  Text();
  Text(std::string text, int size, SDL_Renderer*& m_renderer);
  void loadFont(std::string texture_text, SDL_Renderer*& m_renderer, int size);
  void loadFont(std::string texture_text, SDL_Color text_color, SDL_Renderer*& m_renderer);
  void clear();
};

#endif /* TEXT_H */
