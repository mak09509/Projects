#include <engine.h>
#include <settings.h>
#include <GameObject/basicEnemy.h>

#define DLY (Uint32)(1000/FPS)

void start(SDL_bool *running, SDL_Renderer *renderer) {
    BasicEnemyHandler basicEnemyHandler; basicEnemyHandlerConstruct(&basicEnemyHandler);
    for (int i = 0; i < 4; i++) {
        basicEnemyHandler.push_back(&basicEnemyHandler, basicEnemyConstruct());
    }


    *running = SDL_TRUE;
    Uint64 tick = 0;
    T fps = 120;
    SDL_Event e;

    while (*running == SDL_TRUE) {
        T framestart = (T)SDL_GetTicks();
        
    //EVENT_LISTENER
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                *running = SDL_FALSE;
            }
        }
        if (basicEnemyHandler.size <= 0) *running = SDL_FALSE;
    //EVENT_LISTENER


    //UPDATER
        for (int i = 0; i < basicEnemyHandler.size; i++) {
            BasicEnemy *temp = &((basicEnemyHandler.object)[i]);
            temp->update(temp, &basicEnemyHandler, fps);
        }
    //UPDATER


    //RENDERER
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < basicEnemyHandler.size; i++) {
            BasicEnemy *temp = &((basicEnemyHandler.object)[i]);
            temp->render(temp, &basicEnemyHandler, renderer);
        }
        SDL_RenderPresent(renderer);
    //RENDERER


        printf("%Lf\n", (SDL_GetTicks() - framestart) / 1000);
        tick++;
    }

    stop(&basicEnemyHandler);
}

void stop(BasicEnemyHandler *basicEnemyHandler) {
    basicEnemyHandlerDeconstruct(basicEnemyHandler);
}





