#include "../include/raylib.h"
#include "struct.h"
#include "sMath.h"

//TODO: BETTER DRAWING

void drawObjCircle(Object2D circle){
    if(circle.shape == CIRCLE)
        DrawCircle(circle.position.x, circle.position.y, circle.size.x, circle.color);
}

void drawObjRECT(Object2D sq){
    if(sq.shape == RECT)
        DrawRectangle(sq.position.x, sq.position.y, sq.size.x, sq.size.y, sq.color);
}

// [NOTA] isto desenha os objetos de um mundo do inicio da lista para o fim; os objetos do inicio ficam por baixo dos
// do fim
void drawWorld(World2D world){
    int i = 0;

    while(i<=world.objListLen){
        drawObjCircle(world.objects[i]);
        drawObjRECT(world.objects[i]);
        i++;
    }
}