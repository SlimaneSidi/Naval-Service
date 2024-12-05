#ifndef VISUALS_H
#define VISUALS_H

#include "moteur.h"
#include "../lib/gfxlib/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../lib/gfxlib/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../lib/gfxlib/ESLib.h" // Pour utiliser valeurAleatoire()
#include "../include/ourdrawings.h"

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600

extern int DrawNB; // Variable globale pour savoir quel dessin effectuer

int InitGFXMain(int argc, char **argv);
void cercle(float centreX, float centreY, float rayon);
void gestionEvenement(EvenementGfx evenement);
int GetDrawNB(int NB);
void Draw1();
void Draw2();
void Draw3();
void initializeSquares();
void changeSquareColor(int dockIndex, int squareIndex, int r, int g, int b);





#endif