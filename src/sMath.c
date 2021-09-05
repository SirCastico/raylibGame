#include "../include/raylib.h"
#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include <stdio.h>

int *removeIndexFromIntArray(int *arr, int *len, int ind){
    if(arr && len){
        (*len)--;
        while(ind<*len){
            arr[ind] = arr[ind+1];
            ind++;
        }
        if(*len)
            arr = realloc(arr, *len * sizeof(int));
        else
            arr = NULL;
    }

    return arr;
}

int isIntOnIntArray(int n, int *arr, int len){
    int r=0, i=0;
    if(arr){
        while(i<len){
            if(arr[i] == n){
                r=1;
                break;
            }
            i++;
        }
    }
    return r;
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

Vector2 vector2FloatDiv(Vector2 vec, float f){
    vec.x /= f;
    vec.y /= f;

    return vec;
}

float getVector2Len(Vector2 vec){
    float len = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    return len;
}

Vector2 normalizeVector2(Vector2 vec){
    if(vec.x != 0 && vec.y != 0)
        vec = vector2FloatDiv(vec, getVector2Len(vec));
    return vec;
}
