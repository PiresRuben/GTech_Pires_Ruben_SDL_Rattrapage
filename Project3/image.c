#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

SDL_Texture* loadBMP(const char* file, SDL_Renderer* renderer) {
    SDL_Surface* surface = SDL_LoadBMP(file);
    if (!surface) {
        fprintf(stderr, "Error de chargement image BMP: %s\n", SDL_GetError());
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        fprintf(stderr, "Error de création texture: %s\n", SDL_GetError());
    }
    return texture;
}

void Center(SDL_Renderer* renderer, SDL_Texture* texture, int Wid, int Hei) {
    int imgWidth, imgHeight;
    SDL_QueryTexture(texture, NULL, NULL, &imgWidth, &imgHeight);
    SDL_Rect destRect;
    destRect.x = (Wid - imgWidth) / 2;
    destRect.y = (Hei - imgHeight) / 2;
    destRect.w = imgWidth;
    destRect.h = imgHeight;
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}