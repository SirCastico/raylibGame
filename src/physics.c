#include "../include/raylib.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

Object2D moveObject2D(Object2D object, float delta);
Object2D invertVelocityIfOnScreenEdge(Object2D object, Vector2 screen);
void physicsProcess(World2D *world, float delta, float *nTick);
void updateWorldObjectsPosition(World2D *world, float phTick);
Vector2 getInputForce();
void movePlayerObject2D(Object2D *player, float speed);


Object2D moveObject2D(Object2D object, float delta){
    object.position = vector2Sum(object.position, floatVector2Mult(delta, object.velocity));
    return object;
}

Object2D invertVelocityIfOnScreenEdge(Object2D object, Vector2 screen){
    if(object.position.x > screen.x - object.radius){
        object.velocity.x = -object.velocity.x;
        object.position.x = screen.x - object.radius;
    }
    else if(object.position.x < 0 + object.radius){
        object.velocity.x = -object.velocity.x;
        object.position.x = object.radius;
    }
    if(object.position.y > screen.y - object.radius){
        object.velocity.y = -object.velocity.y;
        object.position.y = screen.y - object.radius;
    }
    else if(object.position.y < 0 + object.radius){
        object.velocity.y = -object.velocity.y;
        object.position.y = object.radius;
    }

    return object;
}


Vector2 getInputForce(){
    Vector2 force;

    force.x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    force.y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);

    force = normalizeVector2(force);

    return force;
}

void movePlayerObject2D(Object2D *player, float speed){
    Vector2 force = getInputForce();
    force = floatVector2Mult(speed, force);

    player->velocity = force;
}

void updateWorldObjectsPosition(World2D *world, float phTick){
    int i=0;

    while(i<=world->objListLen){
        world->objects[i] = invertVelocityIfOnScreenEdge(moveObject2D(world->objects[i], phTick), world->screen);
        i++;
    }
}
void physicsProcess(World2D *world, float delta, float *nTick){
    float phTick = 1.0/60;
    float playerSpeed = 100;
    Object2D *player = getPlayerFromWorld2D(*world); 

    *nTick += delta/phTick;
    //printf("%f\n", *nTick);

    while(*nTick>=1){
        if(player)
            movePlayerObject2D(getPlayerFromWorld2D(*world), playerSpeed);
        updateWorldObjectsPosition(world, phTick);
        *nTick = *nTick - 1;
    }
}
