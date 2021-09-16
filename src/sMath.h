#include "struct.h"

#ifndef __SMATH_H_
#define __SMATH_H_

#define max(a, b) ((a)>(b)? (a) : (b))
#define min(a, b) ((a)<(b)? (a) : (b))

Vector2 vector2Sum(Vector2 vec1, Vector2 vec2);
Vector2 floatVector2Mult(float f, Vector2 vec);
Vector2 vector2FloatDiv(Vector2 vec, float f);
float getVector2Len(Vector2 vec);
Vector2 normalizeVector2(Vector2 vec);
int *removeIndexFromIntArray(int *arr, int *len, int ind);
int isIntOnIntArray(int n, int *arr, int len);

#endif