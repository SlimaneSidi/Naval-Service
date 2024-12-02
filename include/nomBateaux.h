#ifndef NOM_BATEAUX_H
#define NOM_BATEAUX_H

#include "moteur.h"
#define TAILLE 40

extern const char* nomsBateaux[TAILLE];

char* choisirNomAleatoire(const char* nomsBateaux[], int taille);

#endif