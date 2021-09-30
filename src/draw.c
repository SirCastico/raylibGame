#include "raylib.h"
#include "sMath.h"
#include <stdio.h>
#include "ecs.h"

void drawEntCircle(Visual visual, Transform2D transform2D){
    if(visual.shape == CIRCLE)
        DrawCircle(transform2D.position.x, transform2D.position.y, transform2D.size.x, visual.color);
}

void drawEntRect(Visual visual, Transform2D transform2D){
    if(visual.shape == RECT)
        DrawRectangle(transform2D.position.x, transform2D.position.y, transform2D.size.x, transform2D.size.y, visual.color);
}

void drawEntTex(Visual visual, Transform2D transform2D){
    if(visual.shape == TEXTURE)
        DrawTexture(*visual.texture, transform2D.position.x, transform2D.position.y, visual.color);
}

// void unloadWorldTextures(World2D world){
//     int i=0;
//     while(i<=world.objListTop){
//         if(world.objects[i].shape == TEXTURE)
//             UnloadTexture(world.objects[i].texture);

//         i++;
//     }
// }

// [NOTA] isto desenha os objetos de um mundo do inicio da lista para o fim; os objetos do inicio ficam por baixo dos
// do fim; desenha tudo na textura target
void drawWorldToTarget(World2D world, RenderTexture2D target){
    int i = 0;
    BeginTextureMode(target);
        ClearBackground(RAYWHITE);
        while(i<=world.entListTop){
            Component visual = world.compMat[COMP_VISUAL][i];
            Component transform2D = world.compMat[COMP_TRANSFORM2D][i];

            if(visual.compType > -1 && transform2D.compType > -1){
                //printf("Begin Drawing\n");
                drawEntCircle(visual.visual,transform2D.transform2D);
                //printf("1");
                drawEntRect(visual.visual,transform2D.transform2D);
                //printf(" 2");
                drawEntTex(visual.visual,transform2D.transform2D);
                //printf(" 3\n");
            }
            i++;
        }
    EndTextureMode();
}