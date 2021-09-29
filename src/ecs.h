#include "raylib.h"

#ifndef __ECS_H__
#define __ECS_H__

#define COMPONENT_NUMBER 3
// Index dos componentes:
#define COMP_POSVELSIZE 0
#define COMP_COLLISION 1
#define COMP_VISUAL 2

typedef enum EntityTag{
    PLAYER,
    NOTPLAYER
}EntityTag;

typedef enum EntityShape{
    CIRCLE,
    RECT,
    TEXTURE,
    NONE
}EntityShape;

typedef struct PosVelSize{
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
}PosVelSize;

typedef struct Collision{
    int *layers; // NULL = Sem colisão
    int layersTop; // -1 = vazio
}Collision;

typedef struct Visual{
    Texture2D *texture;
    Color color;
    EntityShape shape;
}Visual;

typedef struct Entity2D{
    EntityTag tag;
    int worldInd;
    void *compArr[COMPONENT_NUMBER]; // array de componentes
}Entity2D;

typedef struct World2D{
    Entity2D *entities;
    int entListTop; // -1 = vazio
    Vector2 screen;
}World2D;

Entity2D entity2DInit(EntityTag tag);
World2D world2DInit(Vector2 screen);
void pushEntity2D(Entity2D *entity, World2D *world);
void removeWorld2DEntity(World2D *world,int ind);
Entity2D *getPlayerFromWorld2D(World2D world);
PosVelSize *createPosVelSizeComp(Vector2 pos, Vector2 vel, Vector2 size);
Collision *createCollisionComp(int *layers, int layersTop);
Visual *createVisualComp(Texture2D *texture, Color color, EntityShape shape);
void addPosVelSizeComp(PosVelSize *comp, Entity2D *ent);
void addCollisionComp(Collision *comp, Entity2D *ent);
void addVisualComp(Visual *comp, Entity2D *ent);
PosVelSize *getPosVelSizeComp(Entity2D ent);
Collision *getCollisionComp(Entity2D ent);
Visual *getVisualComp(Entity2D ent);

#endif