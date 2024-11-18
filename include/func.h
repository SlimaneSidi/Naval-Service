#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

typedef struct TYPE_NAVIRE
struct TYPE_NAVIRE {
    char NavirePassagers[] = "navire de passagers";
    char NavireMarchand[] = "navire de marchandises";
    char Petrolier[] = "pétrolier";
    char Yacht[] = "yacht";
};

typedef struct Navire 
struct Navire {
    int id;
    TYPE_NAVIRE type[SIZE];
    char etat[SIZE] // (en mer, accosté, en attente)
    int CapaciteChargement; // (en tonnes)
};



#endif