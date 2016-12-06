#include "Texture.hpp"
Texture::Texture(std::string path, SDL_Renderer*& m_renderer) {
  // Initialize
  mTexture = NULL;
  m_width = 0;
  m_height = 0;
  if (!loadFromFile(path.c_str(), m_renderer)) {
    printf("%s%s\n","Failed to load texture image at", path.c_str());
    exit(1);
  }
}

Texture::Texture() {
}


Texture::~Texture() {
  clear();
}

void Texture::clear() {
  SDL_DestroyTexture(mTexture);
  m_width = 0;
  m_height = 0;
}

bool Texture::loadFromFile(std::string path, SDL_Renderer*& renderer) {
  // Get rid of preexisting texture
  //free();

  // The final texture
  SDL_Texture* newTexture = NULL;

  // Load image at specified path
  SDL_Surface* loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == NULL) {
    std::cout << "Unable to load image" << path.c_str()
              << "SDL_image Error:" << IMG_GetError();
  } else {
    // Color key image
    SDL_SetColorKey(loadedSurface, SDL_TRUE,
                    SDL_MapRGB(loadedSurface->format, 0, 0, 0));

    // Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == NULL) {
      printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(),
             SDL_GetError());
    } else {
      // Get image dimensions
      m_width = loadedSurface->w;
      m_height = loadedSurface->h;
    }

    // Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
  }

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

int Texture::get_width() { return m_width; }

int Texture::get_height() { return m_height; }
