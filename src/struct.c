#include "../include/raylib.h"
#include <stdlib.h>
#include "struct.h"


World2D newWorld2D(Vector2 screen);
Object2D newObject2D(float posX, float posY, float velX, float velY, float radius, Color color, ObjectType type);
void pushObject2D(Object2D object, World2D *world);

Object2D newObject2D(float posX, float posY, float velX, float velY, float radius, Color color, ObjectType type){
    Object2D object = {
        .position.x = posX,
        .position.y = posY,
        .velocity.x = velX,
        .velocity.y = velY,
        .radius = radius,
        .color = color,
        .type = type
    };

    return object;
}

World2D newWorld2D(Vector2 screen){
    World2D world = {
        .screen = screen,
        .objects = NULL,
        .objListLen = -1
    };

    return world;
}

void pushObject2D(Object2D object, World2D *world){
    if(world){
        world->objListLen += 1;
        world->objects = realloc(world->objects, sizeof(Object2D)*(world->objListLen + 1));
        world->objects[world->objListLen] = object;
    }
}