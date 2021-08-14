#include "struct.h"

#ifndef __PHYSICS_H__
#define __PHYSICS_H__

Object2D moveObject2D(Object2D object, float delta);
Object2D invertVelocityIfOnScreenEdge(Object2D object, Vector2 screen);
void physicsProcess(World2D *world, float delta, float *nTick);
void updateWorldObjectsPosition(World2D *world, float phTick);

Vector2 floatVector2Mult(float f, Vector2 vec);
Vector2 vector2Sum(Vector2 vec1, Vector2 vec2);

#endif