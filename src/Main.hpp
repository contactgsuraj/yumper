#ifndef MAIN_H
#define MAIN_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <memory>
#include <string>
#include <vector>
#include "GameLoop.hpp"
#include "Timer.hpp"
#include "WindowInit.hpp"
#include "textures/constant/Bob.hpp"
#include "textures/constant/FPSCounter.hpp"
#include "textures/constant/TextureContainer.hpp"

// Frees media and shuts down SDL
void close();

// The window we'll be rendering to
SDL_Window* m_window = NULL;
SDL_Window& windowRef = *m_window;

// The window renderer
SDL_Renderer* m_renderer = NULL;
SDL_Renderer& rendererRef = *m_renderer;

// GameLoop
std::shared_ptr<GameLoop> gameLoop;

#endif /* MAIN_H */
