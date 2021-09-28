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

Entity2D createPosVelSizeComp(Entity2D entity, Vector2 pos, Vector2 vel, Vector2 size){
    PosVelSize *comp = malloc(sizeof(PosVelSize));
    comp->position = pos;
    comp->velocity = vel;
    comp->size = size;

    entity.compArr[COMP_POSVELSIZE] = comp;

    return entity;
}

Collision *createCollisionComp(int *layers, int layersTop){
    Collision *r = malloc(sizeof(Collision));
    r->layers = layers;
    r->layersTop = layersTop;

    return r;
}

Entity2D createVisualComp(Entity2D entity, Texture2D *texture, Color color, EntityShape shape){
    Visual *comp = malloc(sizeof(Visual));
    comp->texture = texture;
    comp->color = color;
    comp->shape = shape;

    entity.compArr[COMP_VISUAL] = comp;

    return entity;
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

Entity2D *getPlayerFromWorld2D(World2D world){
    int i = world.entListTop;
    while(i>-1){
        if(world.entities[i].tag == PLAYER)
            return &world.entities[i];
        i--;
    }
    return NULL;
}