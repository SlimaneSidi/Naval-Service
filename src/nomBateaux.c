#include "../include/nomBateaux.h"
#include "../include/moteur.h"

char* choisirNomAleatoire(const char* nomsBateaux[], int taille) {
    if (taille <= 0) return NULL; 
    int index = rand() % taille; 
    print choisirNomAleatoire(nomsBateaux, TAILLE);
    return nomsBateaux[index];
}