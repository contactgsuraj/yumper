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

int main(int argc, char* args[]) {
  if (!init(m_window, m_renderer)) {
    std::cerr << "Failed to initialize!" << std::endl;
    return 1;
  }

  if (TTF_Init() == -1) {
    std::cerr << "Failed to initialize TTF lib" << std::endl;
    return 1;
  }

  gameLoop = std::make_shared<GameLoop>(m_renderer);
  //gameLoop->turnOnFPS();
  bool quit = false;

  while (!quit) {
    quit = gameLoop->run();
    SDL_RenderPresent(m_renderer);
  }
  // Free resources and close SDL
  close();
  return 0;
}
