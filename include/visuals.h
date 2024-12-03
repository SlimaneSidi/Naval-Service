#ifndef VISUALS_H
#define VISUALS_H

#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "../lib/gfxlib/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../lib/gfxlib/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../lib/gfxlib/ESLib.h" // Pour utiliser valeurAleatoire()


int drawBoat(int argc, char **argv);
void cercle(float centreX, float centreY, float rayon);
void gestionEvenement(EvenementGfx evenement);

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600


#endif