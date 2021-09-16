#include "raylib.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include "sMath.h"


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

    while(i<=world->objListTop){
        if(world->objects[i].tag == PLAYER)
            updatePlayerObjForceWithInput(&world->objects[i], playerSpeed);
        world->objects[i] = moveObject2D(world->objects[i], phTick);
        i++;
    }
}

Object2D addCollisionLayerToObject(Object2D obj, int layer){
    obj.collision.layersTop += 1;
    obj.collision.layers = realloc(obj.collision.layers, sizeof(int)*(obj.collision.layersTop+1));
    if(obj.collision.layers)
        obj.collision.layers[obj.collision.layersTop] = layer;

    return obj;
}

Object2D removeCollisionLayerFromObject(Object2D obj, int layer){
    int i=0;
    if(obj.collision.layers){
        while(i<=obj.collision.layersTop){
            if(obj.collision.layers[i]==layer){
                removeIndexFromIntArray(obj.collision.layers, &obj.collision.layersTop, i);
                break;
            }
            i++;
        }
    }

    return obj;
}

int doObjectsCollide(Object2D obj1, Object2D obj2){
    int r=0, i=0;

    if(obj1.collision.layers && obj2.collision.layers){
        while(i <= obj1.collision.layersTop){
            if(isIntOnIntArray(obj1.collision.layers[i], obj2.collision.layers, obj2.collision.layersTop)) {
                r=1;
                break;
            }
            i++;
        }
    }
    return r;
}

// [TODO]
void collisionHandler(World2D *world){
    
}

void physicsProcess(World2D *world, float delta, float *nTick){
    float phTick = 1.0/60;

    *nTick += delta/phTick;
    //printf("%f\n", *nTick);

    while(*nTick>=1){
        updateWorldObjectsPosition(world, phTick);
        (*nTick)--;
    }
}
