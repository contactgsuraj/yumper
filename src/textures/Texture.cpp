#include "Texture.hpp"
Texture::Texture(std::string path, SDL_Renderer*& m_renderer) : m_renderer(m_renderer) {
  // Initialize
  mTexture = NULL;
  m_width = 0;
  m_height = 0;

  if (!loadFromFile(path.c_str())) {
    printf("%s%s\n", "Failed to load texture image at", path.c_str());
    exit(1);
  }
}

Texture::Texture(SDL_Renderer*& m_renderer) : m_renderer(m_renderer) {
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

bool Texture::loadFromFile(std::string path) {
  // Get rid of preexisting texture
  clear();

  // The final texture
  SDL_Texture* newTexture = NULL;

  // Load image at specified path
  SDL_Surface* loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == NULL) {
    std::cerr << "Unable to load image" << path.c_str() << "SDL_image Error:" << IMG_GetError();
  }
  // Color key image
  SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0));

  // Create texture from surface pixels
  newTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
  if (newTexture == NULL) {
    printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
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

void Texture::render(int x, int y) {
  // Set rendering space and render to screen
  SDL_Rect renderQuad = {x, y, m_width, m_height};
  SDL_RenderCopy(m_renderer, mTexture, NULL, &renderQuad);
}

void Texture::render(int x, int y, SDL_Rect* clip) {
  // Set rendering space and render to screen
  SDL_Rect renderQuad = {x, y, m_width, m_height};

  // Set clip rendering dimensions
  if (clip != NULL) {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  // Render to screen
  SDL_RenderCopy(m_renderer, mTexture, clip, &renderQuad);
}

void Texture::set_blend_mode(SDL_BlendMode blender) {
  SDL_SetTextureBlendMode(mTexture, blender);
}
void Texture::set_alpha(Uint8 alpha) {
  SDL_SetTextureAlphaMod(mTexture, alpha);
}

int Texture::get_width() {
  return m_width;
}

int Texture::get_height() {
  return m_height;
}
