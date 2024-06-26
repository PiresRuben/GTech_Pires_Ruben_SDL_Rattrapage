#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>

SDL_Texture* loadBMP(const char* file, SDL_Renderer* renderer);

void Center(SDL_Renderer* renderer, SDL_Texture* texture, int Wid, int Hei);


#endif
