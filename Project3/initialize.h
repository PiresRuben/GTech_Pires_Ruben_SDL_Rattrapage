#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <SDL.h>

bool initSDL(SDL_Window** window, SDL_Renderer** renderer, int wid, int hei);

void handleEvents(bool* running, SDL_Rect* rect);

void cleanupSDL(SDL_Window* window, SDL_Renderer* renderer);

#endif
