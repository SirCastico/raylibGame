#include "raylib.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "sMath.h"
#include "ecs.h"

Entity2D entity2DInit(EntityTag tag){
    Entity2D r = {
        .tag = tag,
        .worldInd = -1,
        .compArr = {NULL}
    };

    return r;
}

World2D world2DInit(Vector2 screen){
    World2D world = {
        .entities = NULL,
        .entListTop = -1,
        .screen = screen
    };

    return world;
}

void pushEntity2D(Entity2D *entity, World2D *world){
    if(world){
        world->entListTop += 1;
        world->entities = realloc(world->entities, sizeof(Entity2D)*(world->entListTop + 1));
        world->entities[world->entListTop] = *entity;
        entity->worldInd = world->entListTop;
    }
}

void removeWorld2DEntity(World2D *world,int ind){
    world->entListTop--;
    while(ind<=world->entListTop){
        world->entities[ind] = world->entities[ind+1];
        ind++;
    }
}

PosVelSize *createPosVelSizeComp(Vector2 pos, Vector2 vel, Vector2 size){
    PosVelSize *r = malloc(sizeof(PosVelSize));
    r->position = pos;
    r->velocity = vel;
    r->size = size;

    return r;
}

Collision *createCollisionComp(int *layers, int layersTop){
    Collision *r = malloc(sizeof(Collision));
    r->layers = layers;
    r->layersTop = layersTop;

    return r;
}

Visual *createVisualComp(Texture2D *texture, Color color, EntityShape shape){
    Visual *r = malloc(sizeof(Visual));
    r->texture = texture;
    r->color = color;
    r->shape = shape;

    return r;
}

void addPosVelSizeComp(PosVelSize *comp, Entity2D *ent){
    ent->compArr[COMP_POSVELSIZE] = comp;
}

void addCollisionComp(Collision *comp, Entity2D *ent){
    ent->compArr[COMP_COLLISION] = comp;
}

void addVisualComp(Visual *comp, Entity2D *ent){
    ent->compArr[COMP_VISUAL] = comp;
}

PosVelSize *getPosVelSizeComp(Entity2D ent){
    PosVelSize *r = ent.compArr[COMP_POSVELSIZE];
    return r;
}

Collision *getCollisionComp(Entity2D ent){
    Collision *r = ent.compArr[COMP_COLLISION];
    return r;
}

Visual *getVisualComp(Entity2D ent){
    Visual *r = ent.compArr[COMP_VISUAL];
    return r;
}


Entity2D *getPlayerFromWorld2D(World2D world){
    int i = world.entListTop;
    while(i>-1){
        if(world.entities[i].tag == PLAYER)
            return &world.entities[i];
        i--;
    }
    return NULL;
}