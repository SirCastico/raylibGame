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
        .id=0
    };

    return r;
}

World2D world2DInit(Vector2 screen){
    World2D world = {
        .entities = NULL,
        .entListTop = -1,
        .compMat = malloc(sizeof(Component*)*COMPONENT_NUMBER),
        .screen = screen
    };

    return world;
}

void pushEntity2D(Entity2D *entity, World2D *world){
    if(world){
        world->entListTop += 1;
        world->entities = realloc(world->entities, sizeof(Entity2D)*(world->entListTop + 1));
        world->entities[world->entListTop] = *entity;
        for(int i=0; i<COMPONENT_NUMBER; i++){
            world->compMat[i] = realloc(world->compMat[i], sizeof(Component)*(world->entListTop+1));
            world->compMat[i][world->entListTop].compType = -1;
        }
        entity->worldInd = world->entListTop;
    }
}

// Não testado
void removeWorld2DEntity(World2D *world, Entity2D ent){
    int ind = ent.worldInd;
    world->entListTop--;
    while(ind<=world->entListTop){
        world->entities[ind] = world->entities[ind+1];
        ind++;
    }
    world->entities = realloc(world->entities, sizeof(Entity2D)*(world->entListTop + 1));

    for(int i=0; i<COMPONENT_NUMBER; i++){
        for(int ii=ind; ii<=world->entListTop; ii++){
            world->compMat[i][ii] = world->compMat[i][ii+1];
        }
        world->compMat[i] = realloc(world->compMat[i], sizeof(Component)*(world->entListTop+1));
    }
}

Component createTransform2DComp(Vector2 pos, Vector2 vel, Vector2 size){
    Transform2D comp = {
        .position = pos,
        .velocity = vel,
        .size = size
    };
    Component r = {
        .compType = COMP_TRANSFORM2D,
        .transform2D = comp
    };
    return r;
}

Component createCollisionComp(int *layers, int layersTop){
    Collision comp = {
        .layers = layers,
        .layersTop = layersTop
    }; 
    Component r = {
        .compType = COMP_COLLISION,
        .collision = comp
    };
    return r;
}

Component createVisualComp(Texture2D *texture, Color color, EntityShape shape){
    Visual comp = {
        .texture = texture,
        .color = color,
        .shape = shape
    };
    Component r = {
        .compType = COMP_VISUAL,
        .visual = comp
    };
    return r;
}

void addComponent(Component comp, Entity2D ent, World2D *world){
    if(comp.compType > -1 && ent.worldInd <= world->entListTop){
        world->compMat[comp.compType][ent.worldInd] = comp;
    }
}


Component getComponent(int compType, Entity2D ent, World2D world){
    Component r = {
        .compType = -1,
    };
    if(ent.worldInd <= world.entListTop){
        r = world.compMat[compType][ent.worldInd];
    }
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