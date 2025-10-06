#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#define SCREEN_WIDTH (double)1200
#define SCREEN_HEIGHT (SCREEN_WIDTH*3)/4
#define x(r) 50*r
#define y(r) (0.5*SCREEN_HEIGHT)-x(r)

int main(void) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Game",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int r = 0; r < SCREEN_HEIGHT; r+=50) {
        SDL_RenderDrawLine(renderer, 0, r, SCREEN_WIDTH, r);
    }
    for (int r = 0; r < SCREEN_WIDTH; r+=50) {
        SDL_RenderDrawLine(renderer, r, 0, r, SCREEN_HEIGHT);
    }
    for (double x = 0; x < SCREEN_WIDTH; x+=0.00001) {
        double y = tan(x) + 7*x - 50;
        SDL_RenderDrawPoint(renderer, x(x), y(y));
        SDL_RenderPresent(renderer);
    }

    SDL_Delay(5000);

    printf("Hello World!\n");
    return 0;
}
