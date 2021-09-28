#include "raylib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ecs.h"
#include "physics.h"
#include "draw.h"
#include "sMath.h"

void initAndPushEntitiesToWorld(World2D *world){
    Entity2D player = entity2DInit(PLAYER);
    player = createPosVelSizeComp(player, (Vector2){20,20}, (Vector2){1,1}, (Vector2){20,20});
    player = createVisualComp(player, NULL, RED, CIRCLE);

    pushEntity2D(&player, world);
}

int main(void)
{
    const Vector2 screen = {.x=800, .y=450};
    World2D world = world2DInit(screen);

    float delta;
    float nTick = -1;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screen.x, screen.y, "gaming");
    SetWindowMinSize(320, 240);


    int gameScreenWidth = 640;
    int gameScreenHeight = 480;

    // Render texture initialization, used to hold the rendering result so we can easily resize it
    RenderTexture2D target = LoadRenderTexture(gameScreenWidth, gameScreenHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);  // Texture scale filter to use

    SetTargetFPS(60);

    initAndPushEntitiesToWorld(&world);

    while (!WindowShouldClose())
    {   
        float scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);

        delta = GetFrameTime();

        physicsProcess(&world, delta, &nTick);
        
        drawWorldToTarget(world,target);

        BeginDrawing();
            ClearBackground(BLACK);
            // [TODO] entender como isto funciona
            DrawTexturePro( target.texture, 
                            (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },
                            (Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5f, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5f, (float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, 
                            (Vector2){ 0, 0 },
                            0.0f,
                            WHITE);
            DrawFPS(10, 10);
        EndDrawing();
    }
    UnloadRenderTexture(target);
    //unloadWorldTextures(world);
    CloseWindow();

    return 0;
}
