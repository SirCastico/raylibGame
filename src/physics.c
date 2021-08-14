#include "../include/raylib.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

Object2D moveObject2D(Object2D object, float delta);
Object2D invertVelocityIfOnScreenEdge(Object2D object, Vector2 screen);
void physicsProcess(World2D *world, float delta, float *nTick);
void updateWorldObjectsPosition(World2D *world, float phTick);

Vector2 floatVector2Mult(float f, Vector2 vec);
Vector2 vector2Sum(Vector2 vec1, Vector2 vec2);


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



void updateWorldObjectsPosition(World2D *world, float phTick){
    int i=0;

    while(i<=world->objListLen){
        world->objects[i] = invertVelocityIfOnScreenEdge(moveObject2D(world->objects[i], phTick), world->screen);
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
