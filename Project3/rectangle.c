#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void drawRectangle(SDL_Renderer* renderer, SDL_Rect* rect) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, rect);
}