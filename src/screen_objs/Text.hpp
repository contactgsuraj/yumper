#ifndef TEXT_H
#define TEXT_H
#include "Texture.hpp"

class Text : public Texture {
 private:
  TTF_Font* m_font = NULL;

 public:
  // Renders Text
  void loadFont(std::string texture_text, SDL_Color text_color,
                SDL_Renderer*& m_renderer);
};

#endif /* TEXT_H */
