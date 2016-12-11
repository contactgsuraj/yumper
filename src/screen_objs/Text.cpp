#include "Text.hpp"

Text::Text(std::string text, int size, SDL_Renderer*& m_renderer) : Texture() {
  loadFont(text, m_renderer, size);
}

Text::Text() : Texture() {
}

void Text::loadFont(std::string texture_text, SDL_Color text_color, SDL_Renderer*& m_renderer) {
  if (!m_font) {
    m_font = TTF_OpenFont("assets/HelvetiPixel.ttf", 12);
    if (m_font == NULL) {
      std::cerr << "Failed to load font. SDL_ttf Error: " << TTF_GetError() << std::endl;
    }
  }

  // Render text surface
  SDL_Surface* textSurface = TTF_RenderText_Shaded(m_font, texture_text.c_str(), text_color, default_bg);
  if (textSurface == NULL) {
    printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
  } else {
    // Create texture from surface pixels
    mTexture = SDL_CreateTextureFromSurface(m_renderer, textSurface);
    if (mTexture == NULL) {
      printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
    } else {
      // Get image dimensions
      m_width = textSurface->w;
      m_height = textSurface->h;
    }

    // Get rid of old surface
    SDL_FreeSurface(textSurface);
  }
}

void Text::loadFont(std::string texture_text, SDL_Renderer*& m_renderer, int size) {
  if (!m_font) {
    m_font = TTF_OpenFont("assets/HelvetiPixel.ttf", size);
    if (m_font == NULL) {
      std::cerr << "Failed to load font. SDL_ttf Error: " << TTF_GetError() << std::endl;
    }
  }

  // Render text surface
  SDL_Surface* textSurface = TTF_RenderText_Shaded(m_font, texture_text.c_str(), default_text_color, default_bg);
  if (textSurface == NULL) {
    printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
  } else {
    // Create texture from surface pixels
    mTexture = SDL_CreateTextureFromSurface(m_renderer, textSurface);
    if (mTexture == NULL) {
      printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
    } else {
      // Get image dimensions
      m_width = textSurface->w;
      m_height = textSurface->h;
    }

    // Get rid of old surface
    SDL_FreeSurface(textSurface);
  }
}

void Text::clear() {
  if (m_font) {
    TTF_CloseFont(m_font);
  }
  Texture::clear();
}
