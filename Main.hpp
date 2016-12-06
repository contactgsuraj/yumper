#ifndef MAIN_H
#define MAIN_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <memory>
#include <string>
#include <vector>
#include "Bob.hpp"
#include "IO.hpp"
#include "Timer.hpp"
#include "WindowInit.hpp"
#include "TextureContainer.hpp"

// Frees media and shuts down SDL
void close();
void load();

// The window we'll be rendering to
SDL_Window* m_window = NULL;
SDL_Window& windowRef = *m_window;

// The window renderer
SDL_Renderer* m_renderer = NULL;
SDL_Renderer& rendererRef = *m_renderer;
std::shared_ptr<Bob> bob_c;
std::shared_ptr<TextureContainer> t_container;

// IO handler
IO io = IO();

#endif /* MAIN_H */
