#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>

#include "initialize.h"
#include "image.h"
#include "rectangle.h"

int main() {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* image = NULL;
    const int windowWidth = 800;
    const int windowHeight = 600;
    SDL_Rect rect = { windowWidth / 2 - 25, windowHeight / 2 - 25, 100, 50 };

    if (!initSDL(&window, &renderer, windowWidth, windowHeight)) {
        return 1;
    }
    image = loadBMP("image/image.bmp", renderer);
    if (!image) {
        cleanupSDL(window, renderer, image);
        return 1;
    }
    bool running = true;
    while (running) {
        handleEvents(&running, &rect);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        Center(renderer, image, windowWidth, windowHeight);
        drawRectangle(renderer, &rect);
        SDL_RenderPresent(renderer);
    }
    cleanupSDL(window, renderer, image);
    return 0;
}