#include "struct.h"

#ifndef __DRAW_H__
#define __DRAW_H__

void drawObjCircle(Object2D circle);
void drawObjRECT(Object2D sq);
void drawWorldToTarget(World2D world, RenderTexture2D target);
void unloadWorldTextures(World2D world);

#endif