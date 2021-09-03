#include "../include/raylib.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

Object2D moveObject2D(Object2D object, float delta);
void physicsProcess(World2D *world, float delta, float *nTick);
void updateWorldObjectsPosition(World2D *world, float phTick);
Vector2 getInputForce();
void updatePlayerObjForceWithInput(Object2D *player, float speed);


Object2D moveObject2D(Object2D object, float delta){
    object.position = vector2Sum(object.position, floatVector2Mult(delta, object.velocity));
    return object;
}

Vector2 getInputForce(){
    Vector2 force;

    force.x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    force.y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);

    force = normalizeVector2(force);

    return force;
}

void updatePlayerObjForceWithInput(Object2D *player, float speed){
    Vector2 force = getInputForce();
    force = floatVector2Mult(speed, force);

    player->velocity = force;
}

void updateWorldObjectsPosition(World2D *world, float phTick){
    int i=0;
    int playerSpeed = 200;

    while(i<=world->objListLen){
        if(world->objects[i].tag == PLAYER)
            updatePlayerObjForceWithInput(&world->objects[i], playerSpeed);
        world->objects[i] = moveObject2D(world->objects[i], phTick);
        i++;
    }
}
void physicsProcess(World2D *world, float delta, float *nTick){
    float phTick = 1.0/60;

    *nTick += delta/phTick;
    //printf("%f\n", *nTick);

    while(*nTick>=1){
        updateWorldObjectsPosition(world, phTick);
        *nTick = *nTick - 1;
    }
}
