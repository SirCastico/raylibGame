#include "../include/raylib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "physics.h"

void drawObjCircle(Object2D circle){
    DrawCircle(circle.position.x, circle.position.y, circle.radius, circle.color);
}

void drawWorldCircles(World2D world){
    int i = world.objListLen;

    while(i>-1){
        if(world.objects[i].type == CIRCLE)
            drawObjCircle(world.objects[i]);
        i--;
    }
}


int main(void)
{
    const Vector2 screen = {.x=800, .y=450};
    World2D world = newWorld2D(screen);
    Object2D circle = newObject2D(screen.x/2, screen.y/2, 100, 100, 50, BLACK, CIRCLE);
    pushObject2D(circle, &world);
    float delta;
    float nTick = -1;

    InitWindow(screen.x, screen.y, "gaming");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {   
        delta = GetFrameTime();

        physicsProcess(&world, delta, &nTick);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(10, 10);
            drawWorldCircles(world);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

