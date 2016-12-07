#include "Texture.hpp"
Texture::Texture(std::string path, SDL_Renderer*& m_renderer) {
  // Initialize
  mTexture = NULL;
  m_width = 0;
  m_height = 0;

  if (!loadFromFile(path.c_str(), m_renderer)) {
    printf("%s%s\n", "Failed to load texture image at", path.c_str());
    exit(1);
  }
}

Texture::Texture(bool is_font, std::string path, SDL_Renderer*& m_renderer) {
  // Initialize
  mTexture = NULL;
  m_width = 0;
  m_height = 0;
}

Texture::Texture() {
  // Initialize
  mTexture = NULL;
  m_width = 0;
  m_height = 0;
}

void Texture::clear() {
  if (mTexture) {
    SDL_DestroyTexture(mTexture);
  }
  m_width = 0;
  m_height = 0;
}

bool Texture::loadFromFile(std::string path, SDL_Renderer*& renderer) {
  // Get rid of preexisting texture
  // free();

  // The final texture
  SDL_Texture* newTexture = NULL;

  // Load image at specified path
  SDL_Surface* loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == NULL) {
    std::cerr << "Unable to load image" << path.c_str()
              << "SDL_image Error:" << IMG_GetError();
  }
  // Color key image
  SDL_SetColorKey(loadedSurface, SDL_TRUE,
                  SDL_MapRGB(loadedSurface->format, 0, 0, 0));

  // Create texture from surface pixels
  newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  if (newTexture == NULL) {
    printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(),
           SDL_GetError());
  }
  // Get image dimensions
  m_width = loadedSurface->w;
  m_height = loadedSurface->h;

  // Get rid of old loaded surface
  SDL_FreeSurface(loadedSurface);

  // Return success
  mTexture = newTexture;
  return mTexture != NULL;
}

void Texture::render(int x, int y, SDL_Renderer*& renderer) {
  // Set rendering space and render to screen
  SDL_Rect renderQuad = {x, y, m_width, m_height};
  SDL_RenderCopy(renderer, mTexture, NULL, &renderQuad);
}

void Texture::render(int x, int y, SDL_Rect* clip, SDL_Renderer*& renderer) {
  // Set rendering space and render to screen
  SDL_Rect renderQuad = {x, y, m_width, m_height};

  // Set clip rendering dimensions
  if (clip != NULL) {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  // Render to screen
  SDL_RenderCopy(renderer, mTexture, clip, &renderQuad);
}

void Texture::loadFont(std::string texture_text, SDL_Color text_color,
                       SDL_Renderer*& m_renderer) {
  // Get rid of preexisting texture
  //clear();
  if (!m_font) {
    m_font = TTF_OpenFont("assets/Roboto-Medium.ttf", 12);
    if (m_font == NULL) {
      std::cerr << "Failed to load font. SDL_ttf Error: " << TTF_GetError()
                << std::endl;
    }
  }

  // Render text surface
  SDL_Surface* textSurface = TTF_RenderText_Solid(m_font, texture_text.c_str(), text_color);
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

int Texture::get_width() { return m_width; }

int Texture::get_height() { return m_height; }
