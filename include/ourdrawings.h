#ifndef VISUALS_H
#define VISUALS_H

#include "visuals.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/gfxlib/BmpLib.h"
#include "../lib/gfxlib/GfxLib.h"

typedef struct {
    int x, y;
    int size;
    int r, g, b; // Color components
    char number[2];
} Square;

Square docks[4][4]; // Array to store squares for each dock
Square waitingDock[4]; // Array to store squares for the waiting dock

void Draw1();
void Draw2();
void Draw3();
void initializeSquares();
void changeSquareColor(int dockIndex, int squareIndex, int r, int g, int b);
Button* initializeButton();
void drawButton();
int isButtonClicked(Button* button, int mouseX, int mouseY);

#endif

