#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define RECT_SPEED 5

bool initSDL(SDL_Window** window, SDL_Renderer** renderer, int wid, int hei) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Error d'initialisation SDL: %s\n", SDL_GetError());
        return false;
    }

    *window = SDL_CreateWindow("SDL Project", 800, 600, wid, hei, 4);
    if (*window == NULL) {
        fprintf(stderr, "Error de création fenêtre: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, 2 | 4);
    if (*renderer == NULL) {
        fprintf(stderr, "Error de création renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    return true;
}

void handleEvents(bool* running, SDL_Rect* rect) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *running = false;
        }
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_UP:
                rect->y -= RECT_SPEED;
                break;
            case SDLK_DOWN:
                rect->y += RECT_SPEED;
                break;
            case SDLK_LEFT:
                rect->x -= RECT_SPEED;
                break;
            case SDLK_RIGHT:
                rect->x += RECT_SPEED;
                break;
            }
        }
    }
}

void cleanupSDL(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}