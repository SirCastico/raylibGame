#include "raylib.h"

#ifndef __ECS_H__
#define __ECS_H__

#define COMPONENT_NUMBER 3
// Index dos componentes:
#define COMP_TRANSFORM2D 0
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

typedef struct Transform2D{
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
}Transform2D;

typedef struct Collision{
    int *layers; // NULL = Sem colisão
    int layersTop; // -1 = vazio
}Collision;

typedef struct Visual{
    Texture2D *texture;
    Color color;
    EntityShape shape;
}Visual;

typedef struct Component{
    int compType; // -1 = NULL
    union{
        Transform2D transform2D;
        Collision collision;
        Visual visual;
    };
}Component;

typedef struct Entity2D{
    EntityTag tag;
    int id;
    int worldInd;
}Entity2D;

typedef struct World2D{
    Entity2D *entities;
    int entListTop; // -1 = vazio
    Component **compMat;
    Vector2 screen;
}World2D;

Entity2D entity2DInit(EntityTag tag);
World2D world2DInit(Vector2 screen);
void pushEntity2D(Entity2D *entity, World2D *world);
void removeWorld2DEntity(World2D *world, Entity2D ent);
Entity2D *getPlayerFromWorld2D(World2D world);
Component createTransform2DComp(Vector2 pos, Vector2 vel, Vector2 size);
Component createCollisionComp(int *layers, int layersTop);
Component createVisualComp(Texture2D *texture, Color color, EntityShape shape);
void addComponent(Component comp, Entity2D ent, World2D *world);
Component getComponent(int compType, Entity2D ent, World2D world);



#endif