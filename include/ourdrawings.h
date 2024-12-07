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
    int width, height;
    char label[20];
} Button;


void Draw1();
void Draw2();
void Draw3();
void initializeSquares();
void changeSquareColor(int dockIndex, int squareIndex, int r, int g, int b);
void initializeButton();
void drawButton(Button button);
int isButtonClicked(Button button, int mouseX, int mouseY);




#endif

