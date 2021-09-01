#include "../include/raylib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "physics.h"
#include "draw.h"


int main(void)
{
    const Vector2 screen = {.x=800, .y=450};
    World2D world = newWorld2D(screen);
    // [NOTA] Circle e Player iniciais são diferentes dos guardados no mundo
    Object2D circle = newObject2D(screen.x/2, screen.y/2, 100, 100, 50, BLACK, NOTPLAYER, CIRCLE);
    Object2D player = newObject2D(screen.x/2, screen.y/2+10, 0, 0, 50, RED, PLAYER, CIRCLE);
    pushObject2D(circle, &world);
    pushObject2D(player, &world);
    float delta;
    float nTick = -1;

    InitWindow(screen.x, screen.y, "gaming");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {   
        delta = GetFrameTime();

        physicsProcess(&world, delta, &nTick);

        //printf("%f %f\n", player.position.x, player.position.y);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(10, 10);
            drawWorldCircles(world);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

