#ifndef VISUALS_H
#define VISUALS_H

#include "visuals.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/gfxlib/BmpLib.h"
#include "../lib/gfxlib/GfxLib.h"


void Draw1();
void Draw2();
void Draw3();
void initializeSquares();
void changeSquareColor(int dockIndex, int squareIndex, int r, int g, int b);

#endif

