#ifndef VISUALS_H
#define VISUALS_H

#include "moteur.h"
#include "../lib/gfxlib/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../lib/gfxlib/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../lib/gfxlib/ESLib.h" // Pour utiliser valeurAleatoire()

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600

typedef struct {
    int x, y;
    int width, height;
    char label[20];
} Button;

typedef struct {
    int x, y;
    int size;
    int r, g, b; // Color components
    char number[2];
} Square;

extern int DrawNB; // Variable globale pour savoir quel dessin effectuer
extern Square docks[4][4]; // Array to store squares for each dock
extern Square waitingDock[4]; // Array to store squares for the waiting dock

int drawBoat(int argc, char **argv);
int InitGFXMain(int argc, char **argv);
void cercle(float centreX, float centreY, float rayon);
void gestionEvenement(EvenementGfx evenement);
int GetDrawNB(int NB);
void Draw1();
void Draw2();
void Draw3();
void initializeSquares();
void changeSquareColor(int dockIndex, int squareIndex, int r, int g, int b);
extern Button* initializeButton(int x, int y, const char* label);
extern void drawButton(Button* button);
extern int isButtonClicked(Button* button, int mouseX, int mouseY);
void KillWindowToDraw();

#endif // VISUALS_H
