#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <settings.h>
#include <engine.h>

void initSystem(SDL_Window **window, SDL_Renderer **renderer);
void cleanSystem(SDL_Window **window, SDL_Renderer **renderer);

int main(void) {
    srand(time(NULL));

    SDL_bool running = SDL_FALSE;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    initSystem(&window, &renderer);

    start(&running, renderer);

    cleanSystem(&window, &renderer);
    return 0;
}



void initSystem(SDL_Window **window, SDL_Renderer **renderer) {

    SDL_Init(SDL_INIT_EVERYTHING);
    *window = SDL_CreateWindow(WINDOW_TITLE,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            SDL_WINDOW_SHOWN);
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
}

void cleanSystem(SDL_Window **window, SDL_Renderer **renderer) {

    SDL_DestroyRenderer(*renderer);
    *renderer = NULL;
    
    SDL_DestroyWindow(*window);
    *window = NULL;

    SDL_Quit();
}



















