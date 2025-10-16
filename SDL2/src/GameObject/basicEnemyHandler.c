#include <GameObject/basicEnemy.h>

void push_back(BasicEnemyHandler *handler, BasicEnemy value) {
    if (handler->size == handler->capacity) {
        handler->capacity *= 2;
        handler->object = realloc(handler->object, sizeof(BasicEnemy) * handler->capacity);
    }
    (handler->object)[handler->size++] = value;
}

void erase(BasicEnemyHandler *handler, BasicEnemy *value) {
    basicEnemyDeconstruct(value);
    BasicEnemy *last = &((handler->object)[handler->size - 1]);

    BasicEnemy tmp = *value;
    *value = *last;
    *last = tmp;
    
    handler->size--;
}

void basicEnemyHandlerConstruct(BasicEnemyHandler *handler) {
    handler->push_back = push_back;
    handler->erase = erase;
    handler->object = malloc(sizeof(BasicEnemy) * 8);
    handler->size = 0;
    handler->seen = 0;
    handler->capacity = 8;
}

void basicEnemyHandlerDeconstruct(BasicEnemyHandler *handler) {
    free(handler->object);
    handler->object = NULL;
    handler->size = 0;
    handler->seen = 0;
    handler->capacity = 0;
}

