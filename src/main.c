#include "../include/raylib.h"
#include <stdio.h>
#include <math.h>

typedef struct Circle2D{
    Vector2 position;
    Vector2 velocity;
    float radius;
    Color color;
}Circle2D;

Circle2D moveCircle2D(Circle2D circle, float delta);
Circle2D invertVelocityIfOnScreenEdge(Circle2D circle, Vector2 screen);
Circle2D newCircle(float posX, float posY, float velX, float velY, float radius, Color color);

Vector2 floatVector2Mult(float f, Vector2 vec);
Vector2 vector2Sum(Vector2 vec1, Vector2 vec2);
float getDeltaTime();

//fazer physicsprocess, chamado 60 vezes por segundo/delta fixado.
//quando delta é maior que 0.016, contar quantas n vezes é maior e fazer a simulação n vezes

int main(void)
{
    const Vector2 screen = {.x=800, .y=450};
    Circle2D circle = newCircle(screen.x/2, screen.y/2, 100, 100, 50, BLACK);
    float delta;
    float nTick = -1;
    float phTick = 1.0/60;

    InitWindow(screen.x, screen.y, "gaming");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {   
        // Processing Physics //
        delta = GetFrameTime();
        nTick += delta/phTick;
        //printf("%f\n", nTick);
        while(nTick>=1){
            circle = invertVelocityIfOnScreenEdge(moveCircle2D(circle, phTick), screen);
            nTick--;
        }
        // End of Physics //
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(10, 10);
            DrawCircle(circle.position.x, circle.position.y, circle.radius, circle.color);
        EndDrawing();
        //printf("%f : %f \n", circle.position.x, circle.position.y);
        //printf("%f\n", delta);
    }

    CloseWindow();

    return 0;
}

Circle2D moveCircle2D(Circle2D circle, float delta){
    circle.position = vector2Sum(circle.position, floatVector2Mult(delta, circle.velocity));
    return circle;
}

Circle2D invertVelocityIfOnScreenEdge(Circle2D circle, Vector2 screen){
    if(circle.position.x > screen.x - circle.radius){
        circle.velocity.x = -circle.velocity.x;
        circle.position.x = screen.x - circle.radius;
    }
    else if(circle.position.x < 0 + circle.radius){
        circle.velocity.x = -circle.velocity.x;
        circle.position.x = circle.radius;
    }
    if(circle.position.y > screen.y - circle.radius){
        circle.velocity.y = -circle.velocity.y;
        circle.position.y = screen.y - circle.radius;
    }
    else if(circle.position.y < 0 + circle.radius){
        circle.velocity.y = -circle.velocity.y;
        circle.position.y = circle.radius;
    }

    return circle;
}

Vector2 vector2Sum(Vector2 vec1, Vector2 vec2){
    vec1.x += vec2.x;
    vec1.y += vec2.y;

    return vec1;
}

Vector2 floatVector2Mult(float f, Vector2 vec){
    vec.x *= f;
    vec.y *= f;
    return vec;
}

Circle2D newCircle(float posX, float posY, float velX, float velY, float radius, Color color){
    Circle2D circle = {
        .position.x = posX,
        .position.y = posY,
        .velocity.x = velX,
        .velocity.y = velY,
        .radius = radius,
        .color = color
    };

    return circle;
}
