#include "ecs.h"

#ifndef __PHYSICS_H__
#define __PHYSICS_H__

Component moveEntity2D(Component comp, float delta);
void updateWorldObjectsPosition(World2D *world, float phTick);
void physicsProcess(World2D *world, float delta, float *nTick);

#endif