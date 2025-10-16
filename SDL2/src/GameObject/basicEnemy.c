#include <settings.h>
#include <GameObject/basicEnemy.h>

static SDL_Rect toSDLCoordinateSystem(T x, T y) {
    SDL_Rect result = {
        .x = x,
        .y = WINDOW_HEIGHT - y,
        .w = BASICENEMY_SIZE,
        .h = -BASICENEMY_SIZE
    };
    return result;
}

static void update(BasicEnemy *object, BasicEnemyHandler *handler, T fps) {
    //object->velX = (T)(rand() % (int)(BASICENEMY_MAX_VELOCITY / fps));
    //object->velY = (T)(rand() % (int)(BASICENEMY_MAX_VELOCITY / fps));
    object->x += object->velX;
    object->y += object->velY;

    if (object->seen) {
        if (object->x < 0) {
            object->x = 0;
            object->velX *= -1;
            object->health--;
        }
        if (object->x > WINDOW_WIDTH - BASICENEMY_SIZE) {
            object->x = WINDOW_WIDTH - BASICENEMY_SIZE;
            object->velX *= -1;
            object->health--;
        }
        if (object->y < 0) {
            object->y = 0;
            object->velY *= -1;
            object->health--;
        }
        if (object->y > WINDOW_HEIGHT - BASICENEMY_SIZE) {
            object->y = WINDOW_HEIGHT - BASICENEMY_SIZE;
            object->velY *= -1;
            object->health--;
        }
    } else {
        if (object->x < 0 - BASICENENY_SPAWNER_EDGE_LENGTH) {
            object->x = 0 - BASICENENY_SPAWNER_EDGE_LENGTH;
            object->velX *= -1;
        }
        if (object->x > WINDOW_WIDTH + BASICENENY_SPAWNER_EDGE_LENGTH - BASICENEMY_SIZE) {
            object->x = WINDOW_WIDTH + BASICENENY_SPAWNER_EDGE_LENGTH - BASICENEMY_SIZE;
            object->velX *= -1;
        }
        if (object->y < 0 - BASICENENY_SPAWNER_EDGE_LENGTH) {
            object->y = 0 - BASICENENY_SPAWNER_EDGE_LENGTH;
            object->velY *= -1;
        }
        if (object->y > WINDOW_HEIGHT + BASICENENY_SPAWNER_EDGE_LENGTH - BASICENEMY_SIZE) {
            object->y = WINDOW_HEIGHT + BASICENENY_SPAWNER_EDGE_LENGTH - BASICENEMY_SIZE;
            object->velY *= -1;
        }
        if ((object->x >= 0 && object->x <= WINDOW_WIDTH - BASICENEMY_SIZE) &&
            (object->y >= 0 && object->y <= WINDOW_HEIGHT - BASICENEMY_SIZE)) {
            object->seen = SDL_TRUE;
            handler->seen++;
        }
    }

    if (object->health <= 0) handler->erase(handler, object);
}

static void render(BasicEnemy *object, BasicEnemyHandler *handler, SDL_Renderer *renderer) {

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_Rect rect = toSDLCoordinateSystem(object->x, object->y);
    SDL_RenderFillRect(renderer, &rect);
}

BasicEnemy basicEnemyConstruct() {
    BasicEnemy object;

    object.update = update;


    object.render = render;


    object.velX = 1;


    object.velY = 1;

    
    object.health = 3;


    object.seen = SDL_FALSE;


    Uint8 op = rand() % 4;
    if (op == 0) {
        object.x = (T)(rand() % (int)(WINDOW_WIDTH - BASICENEMY_SIZE));
        object.y = -(T)(rand() % (int)(BASICENENY_SPAWNER_EDGE_LENGTH - BASICENEMY_SIZE));
        if (rand() % 2) object.velX *= -1;
        if (rand() % 2) object.velY *= -1;
    }
    else if (op == 1) {
        object.x = (T)(rand() % (int)(WINDOW_WIDTH - BASICENEMY_SIZE));
        object.y = (T)(rand() % (int)BASICENENY_SPAWNER_EDGE_LENGTH) + WINDOW_HEIGHT;
        if (rand() % 2) object.velX *= -1;
        object.velY *= -1;
    }
    else if (op == 2) {
        object.x = -(T)(rand() % (int)BASICENENY_SPAWNER_EDGE_LENGTH);
        object.y = (T)(rand() % (int)(WINDOW_HEIGHT - BASICENEMY_SIZE)) + BASICENEMY_SIZE;
        if (rand() % 2) object.velX *= -1;
        if (rand() % 2) object.velY *= -1;
    }
    else {
        object.x = (T)(rand() % (int)BASICENENY_SPAWNER_EDGE_LENGTH - BASICENEMY_SIZE) + WINDOW_WIDTH;
        object.y = (T)(rand() % (int)(WINDOW_HEIGHT - BASICENEMY_SIZE)) + BASICENEMY_SIZE;
        object.velX *= -1;
        if (rand() % 2) object.velY *= -1;
    }

    return object;
}

void basicEnemyDeconstruct(BasicEnemy *object) {
    object->update = NULL;
    object->render = NULL;
    object->velX = 0;
    object->velY = 0;
    object->x = 0;
    object->y = 0;
}






