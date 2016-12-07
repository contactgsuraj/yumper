#include "Text.hpp"
void Text::loadFont(std::string texture_text, SDL_Color text_color,
                    SDL_Renderer*& m_renderer) {
  // Get rid of preexisting texture
  clear();
  if (!m_font) {
    m_font = TTF_OpenFont("assets/Roboto-Medium.ttf", 12);
    if (m_font == NULL) {
      std::cerr << "Failed to load font. SDL_ttf Error: " << TTF_GetError()
                << std::endl;
    }
  }

  // Render text surface
  SDL_Surface* textSurface =
      TTF_RenderText_Solid(m_font, texture_text.c_str(), text_color);
  if (textSurface == NULL) {
    printf("Unable to render text surface! SDL_ttf Error: %s\n",
           TTF_GetError());
  } else {
    // Create texture from surface pixels
    mTexture = SDL_CreateTextureFromSurface(m_renderer, textSurface);
    if (mTexture == NULL) {
      printf("Unable to create texture from rendered text! SDL Error: %s\n",
             SDL_GetError());
    } else {
      // Get image dimensions
      m_width = textSurface->w;
      m_height = textSurface->h;
    }

    // Get rid of old surface
    SDL_FreeSurface(textSurface);
  }
}
