#include "Main.hpp"
void close() {
  // Destroy windows / renderers
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  m_window = NULL;
  m_renderer = NULL;

  // Close SDL sub processes
  IMG_Quit();
  TTF_Quit();
  SDL_Quit();
}

void load() {
  bob_c = std::make_shared<Bob>(m_renderer);
  t_container = std::make_shared<TextureContainer>(m_renderer);
  io = std::make_shared<IO>(m_renderer);
}

int main(int argc, char* args[]) {
  // Initialise windows
  if (!init(m_window, m_renderer)) {
    printf("Failed to initialize!\n");
    return 1;
  }

  if (TTF_Init() == -1) {
    std::cerr << "Failed to initialize TTF lib" << std::endl;
    return 1;
  }

  // Loading assets
  load();
  bool quit = false;

  while (!quit) {
    quit = io->run(m_renderer, bob_c, t_container);
    SDL_RenderPresent(m_renderer);
  }
  // Free resources and close SDL
  close();
  return 0;
}
