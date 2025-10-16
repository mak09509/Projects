#ifndef _BASICENEMY_H
#define _BASICENEMY_H
#include <SDL2/SDL.h>
#include <settings.h>

#define BASICENEMY_MAX_VELOCITY (T) 100                                     // pixel(s) per second
#define BASICENEMY_SIZE (T) 10                                              // pixel(s)
#define BASICENENY_SPAWNER_EDGE_LENGTH (WINDOW_HEIGHT/2)                    // pixel(s)

typedef struct BasicEnemy BasicEnemy;
typedef struct BasicEnemyHandler BasicEnemyHandler;

struct BasicEnemy {
    long double x, y, velX, velY;
    long double health;
    SDL_bool seen;
    void (*update)(BasicEnemy *object, BasicEnemyHandler *handler, T fps);
    void (*render)(BasicEnemy *object, BasicEnemyHandler *handler, SDL_Renderer *renderer);
};
struct BasicEnemyHandler {
    BasicEnemy* object;
    size_t size;
    size_t seen;
    size_t capacity;
    void (*push_back)(BasicEnemyHandler *handler, BasicEnemy object);
    void (*erase)(BasicEnemyHandler *handler, BasicEnemy *value);
};

void basicEnemyHandlerConstruct(BasicEnemyHandler *handler);
void basicEnemyHandlerDeconstruct(BasicEnemyHandler *handler);

BasicEnemy basicEnemyConstruct();
void basicEnemyDeconstruct(BasicEnemy *object);

#endif
