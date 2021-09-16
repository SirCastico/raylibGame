#include "raylib.h"

#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef enum ObjectTag{
    PLAYER,
    NOTPLAYER
}ObjectTag;

typedef enum ObjectShape{
    CIRCLE,
    RECT,
    TEXTURE,
    NONE
}ObjectShape;

typedef struct CollisionLayers{
    int *layers; // NULL = Sem colisão
    int layersTop; // -1 = vazio
}CollisionLayers;

// [TODO] hitbox
typedef struct Object2D{
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
    CollisionLayers collision;
    Texture2D texture;
    Color color;
    ObjectTag tag;
    ObjectShape shape;
}Object2D;

typedef struct World2D{
    Object2D *objects;
    int objListTop; // -1 = vazio
    Vector2 screen;
}World2D;

Vector2 newVector(float x, float y);
World2D newWorld2D(Vector2 screen);
void pushObject2D(Object2D object, World2D *world);
Object2D *getPlayerFromWorld2D(World2D world);
void printTag(Object2D obj);
void printObjTag(World2D world);


#endif