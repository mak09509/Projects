#ifndef _ENGINE_H
#define _ENGINE_H

#include <SDL2/SDL.h>
#include <GameObject/basicEnemy.h>

void start(SDL_bool *running, SDL_Renderer *renderer);
void loop(SDL_bool *running, SDL_Renderer *renderer);
void stop(BasicEnemyHandler *basicEnemyHandler);

#endif
