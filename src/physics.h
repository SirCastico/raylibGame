#include "struct.h"

#ifndef __PHYSICS_H__
#define __PHYSICS_H__

Object2D moveObject2D(Object2D object, float delta);
void physicsProcess(World2D *world, float delta, float *nTick);
void updateWorldObjectsPosition(World2D *world, float phTick);
Vector2 getInputForce();
void updatePlayerObjForceWithInput(Object2D *player, float speed);

#endif