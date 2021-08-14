#include "../include/raylib.h"

#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef enum ObjectType{
    CIRCLE,
    SQUARE
}ObjectType;

typedef struct Object2D{
    Vector2 position;
    Vector2 velocity;
    float radius;
    Color color;
    ObjectType type;
}Object2D;

typedef struct World2D{
    Object2D *objects;
    int objListLen;
    Vector2 screen;
}World2D;

World2D newWorld2D(Vector2 screen);
Object2D newObject2D(float posX, float posY, float velX, float velY, float radius, Color color, ObjectType type);
void pushObject2D(Object2D object, World2D *world);

#endif