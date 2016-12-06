#include "Main.hpp"
void close() {
  bob_c->clear();
  t_container->clear();
  // Destroy window
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  m_window = NULL;
  m_renderer = NULL;

  // Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

void load() {
  bob_c = std::make_shared<Bob>(m_renderer);
  t_container = std::make_shared<TextureContainer>(m_renderer);
}

int main(int argc, char* args[]) {

  /*Initialise windows*/
  if (!init(m_window, m_renderer)) {
    printf("Failed to initialize!\n");
    return 1;
  }

  // Textures
  load();
  io.run(m_renderer, bob_c, t_container);
  // Free resources and close SDL
  close();
  return 0;
}
