#include "../include/raylib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "physics.h"
#include "draw.h"


void initAndPushObjectsToWorld(World2D *world){
    Object2D rect = {
        .position = {0, 0},
        .velocity = {0, 0},
        .size = {50, 50},
        .color = BLACK,
        .tag = NOTPLAYER,
        .shape = RECT
    };
    Object2D player = {
        .position = {world->screen.x/2, world->screen.y/2},
        .velocity = {0, 0},
        .size = {10, 0},
        .color = RED,
        .tag = PLAYER,
        .shape = CIRCLE
    };

    pushObject2D(rect, world);
    pushObject2D(player, world);

}

int main(void)
{
    const Vector2 screen = {.x=800, .y=450};
    World2D world = newWorld2D(screen);

    initAndPushObjectsToWorld(&world);

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
            drawWorld(world);
            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

