#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
#define NP "navire de passagers"
#define NM "navire de marchandises"
#define P "pétrolier"
#define Y "yacht"

typedef struct TYPE_NAVIRE TYPE_NAVIRE;
struct TYPE_NAVIRE {
    char NavirePassagers[50];
    char NavireMarchand[50];    //= "navire de marchandises";
    char Petrolier[50];          // =  "pétrolier";
    char Yacht[50];             // = "yacht";
};

typedef struct Navire  Navire;
struct Navire {
    int id;
    TYPE_NAVIRE type[SIZE];
    char etat[SIZE]; // (en mer, accosté, en attente)
    int CapaciteChargement; // (en tonnes)
};

typedef struct Quai Quai;
struct Quai {
    int NumeroQuai;
    int QuaiSize;
    int Profondeur;
    TYPE_NAVIRE TypeNavire;
    int MaxNaviresAccostés;
    Navire *NextNavire; //Liste chaînée des navires en attente d'accostage
};

Quai CreerQuai(Quai *quai);
Navire CreerNavire(Navire *navire);
void AfficherQuai(Quai *quai);
void AfficherNavire(Navire *navire);

#endif