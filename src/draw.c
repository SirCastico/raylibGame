#include "raylib.h"
#include "sMath.h"
#include <stdio.h>
#include "ecs.h"

void drawEntCircle(Visual visual, PosVelSize posVelSize){
    if(visual.shape == CIRCLE)
        DrawCircle(posVelSize.position.x, posVelSize.position.y, posVelSize.size.x, visual.color);
}

void drawEntRect(Visual visual, PosVelSize posVelSize){
    if(visual.shape == RECT)
        DrawRectangle(posVelSize.position.x, posVelSize.position.y, posVelSize.size.x, posVelSize.size.y, visual.color);
}

void drawEntTex(Visual visual, PosVelSize posVelSize){
    if(visual.shape == CIRCLE)
        DrawTexture(*visual.texture, posVelSize.position.x, posVelSize.position.y, visual.color);
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
            Visual *visual = world.entities[i].compArr[COMP_VISUAL];
            PosVelSize *posVelSize = world.entities[i].compArr[COMP_POSVELSIZE];
            if(visual && posVelSize){
                drawEntCircle(*visual,*posVelSize);
                drawEntRect(*visual,*posVelSize);
                drawEntTex(*visual,*posVelSize);
            }
            i++;
        }
    EndTextureMode();
}