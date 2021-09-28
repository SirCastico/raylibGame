#include "ecs.h"

#ifndef __PHYSICS_H__
#define __PHYSICS_H__

Entity2D moveObject2D(Entity2D entity, float delta);
void updateWorldObjectsPosition(World2D *world, float phTick);
void physicsProcess(World2D *world, float delta, float *nTick);

#endif