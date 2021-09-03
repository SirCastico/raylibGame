#include "../include/raylib.h"
#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include <stdio.h>

Vector2 newVector(float x, float y);
World2D newWorld2D(Vector2 screen);
Object2D newObject2D(float posX, float posY, float velX, float velY, float width, float height, Color color, ObjectTag tag, ObjectShape shape);
void pushObject2D(Object2D object, World2D *world);
Vector2 vector2Sum(Vector2 vec1, Vector2 vec2);
Vector2 floatVector2Mult(float f, Vector2 vec);
Vector2 vector2FloatDiv(Vector2 vec, float f);
float getVector2Len(Vector2 vec);
Vector2 normalizeVector2(Vector2 vec);
Object2D *getPlayerFromWorld2D(World2D world);

Vector2 newVector(float x, float y){
    return (Vector2) {x,y};
}

Object2D newObject2D(float posX, float posY, float velX, float velY, float width, float height, Color color, ObjectTag tag, ObjectShape shape){
    Object2D object = {
        .position.x = posX,
        .position.y = posY,
        .velocity.x = velX,
        .velocity.y = velY,
        .size.x = width,
        .size.y = height,
        .color = color,
        .tag = tag,
        .shape = shape
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

Vector2 vector2Sum(Vector2 vec1, Vector2 vec2){
    vec1.x += vec2.x;
    vec1.y += vec2.y;

    return vec1;
}

Vector2 floatVector2Mult(float f, Vector2 vec){
    vec.x *= f;
    vec.y *= f;
    return vec;
}

Vector2 vector2FloatDiv(Vector2 vec, float f){
    vec.x /= f;
    vec.y /= f;

    return vec;
}

float getVector2Len(Vector2 vec){
    float len = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    return len;
}

Vector2 normalizeVector2(Vector2 vec){
    if(vec.x != 0 && vec.y != 0)
        vec = vector2FloatDiv(vec, getVector2Len(vec));
    return vec;
}

void printTag(Object2D obj){
    switch (obj.tag) {
        case PLAYER:
            printf("PLAYER ");
            break;
        case NOTPLAYER:
            printf("NOTPLAYER ");
            break;
    }
}

void printObjTag(World2D world){
    int i = world.objListLen;

    while(i>-1){
        printf("%d ", i);
        printTag(world.objects[i]);
        i--;
    }
    putchar('\n');
}

Object2D *getPlayerFromWorld2D(World2D world){
    int i = world.objListLen;
    while(i>-1){
        if(world.objects[i].tag == PLAYER)
            return &world.objects[i];
        i--;
    }
    return NULL;
}
