#include "../include/raylib.h"
#include "struct.h"

//TODO: BETTER DRAWING

void drawObjCircle(Object2D circle){
    DrawCircle(circle.position.x, circle.position.y, circle.radius, circle.color);
}

void drawWorldCircles(World2D world){
    int i = world.objListLen;

    while(i>-1){
        if(world.objects[i].shape == CIRCLE)
            drawObjCircle(world.objects[i]);
        i--;
    }
}