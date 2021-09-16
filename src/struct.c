#include "raylib.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "sMath.h"


Vector2 newVector(float x, float y){
    return (Vector2) {x,y};
}

Object2D initObject2D(){
    Object2D obj = {
        .position = {0,0},
        .velocity = {0,0},
        .size = {0,0},
        .collision = {NULL, -1},
        .color = RED,
        .tag = NOTPLAYER,
        .shape = NONE
    };

    return obj;
}


World2D newWorld2D(Vector2 screen){
    World2D world = {
        .objects = NULL,
        .objListTop = -1,
        .screen = screen
    };

    return world;
}

void pushObject2D(Object2D object, World2D *world){
    if(world){
        world->objListTop += 1;
        world->objects = (Object2D*)realloc(world->objects, sizeof(Object2D)*(world->objListTop + 1));
        world->objects[world->objListTop] = object;
    }
}

void printTag(Object2D obj){
    switch (obj.tag) {
        case PLAYER:
            printf("PLAYER ");
            break;
        case NOTPLAYER:
            printf("NOTPLAYER ");
            break;
    }
}

void printObjTag(World2D world){
    int i = world.objListTop;

    while(i>-1){
        printf("%d ", i);
        printTag(world.objects[i]);
        i--;
    }
    putchar('\n');
}

Object2D *getPlayerFromWorld2D(World2D world){
    int i = world.objListTop;
    while(i>-1){
        if(world.objects[i].tag == PLAYER)
            return &world.objects[i];
        i--;
    }
    return NULL;
}
