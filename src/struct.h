#include "../include/raylib.h"

#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef enum ObjectTag{
    PLAYER,
    NOTPLAYER
}ObjectTag;

typedef enum ObjectShape{
    CIRCLE,
    RECT
}ObjectShape;

typedef struct Object2D{
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
    Color color;
    ObjectTag tag;
    ObjectShape shape;
}Object2D;

typedef struct World2D{
    Object2D *objects;
    int objListLen;
    Vector2 screen;
}World2D;

Vector2 newVector(float x, float y);
World2D newWorld2D(Vector2 screen);
Object2D newObject2D(float posX, float posY, float velX, float velY, float width, float height, Color color, ObjectTag tag, ObjectShape shape);
void pushObject2D(Object2D object, World2D *world);
Vector2 vector2Sum(Vector2 vec1, Vector2 vec2);
Vector2 floatVector2Mult(float f, Vector2 vec);
Vector2 vector2FloatDiv(Vector2 vec, float f);
float getVector2Len(Vector2 vec);
Vector2 normalizeVector2(Vector2 vec);
Vector2 vector2FloatDiv(Vector2 vec, float f);
float getVector2Len(Vector2 vec);
Vector2 normalizeVector2(Vector2 vec);
Object2D *getPlayerFromWorld2D(World2D world);
void printTag(Object2D obj);
void printObjTag(World2D world);


#endif