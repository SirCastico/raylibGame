#include "raylib.h"
#include "struct.h"
#include "sMath.h"
#include <stdio.h>

//TODO: BETTER DRAWING

void drawObjCircle(Object2D circle){
    if(circle.shape == CIRCLE)
        DrawCircle(circle.position.x, circle.position.y, circle.size.x, circle.color);
}

void drawObjRECT(Object2D sq){
    if(sq.shape == RECT)
        DrawRectangle(sq.position.x, sq.position.y, sq.size.x, sq.size.y, sq.color);
}

void drawObjTex(Object2D obj){
    if(obj.shape == TEXTURE){
        DrawTexture(obj.texture, obj.position.x, obj.position.y, obj.color);
    }
}

void unloadWorldTextures(World2D world){
    int i=0;
    while(i<=world.objListTop){
        if(world.objects[i].shape == TEXTURE)
            UnloadTexture(world.objects[i].texture);

        i++;
    }
}

// [NOTA] isto desenha os objetos de um mundo do inicio da lista para o fim; os objetos do inicio ficam por baixo dos
// do fim; desenha tudo na textura target
void drawWorldToTarget(World2D world, RenderTexture2D target){
    int i = 0;

    BeginTextureMode(target);
        ClearBackground(RAYWHITE);
        while(i<=world.objListTop){
            drawObjCircle(world.objects[i]);
            drawObjRECT(world.objects[i]);
            drawObjTex(world.objects[i]);
            i++;
        }
    EndTextureMode();
}