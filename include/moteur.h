#ifndef MOTEUR_H
#define MOTEUR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
#define NP "navire de passagers"
#define NM "navire de marchandises"
#define P "pétrolier"
#define Y "yacht"

typedef struct TYPE_NAVIRE{
    char NavirePassagers[SIZE];   //= "navire de passagers";
    char NavireMarchand[SIZE];    //= "navire de marchandises";
    char Petrolier[SIZE];         // =  "pétrolier";
    char Yacht[SIZE];             // = "yacht";
}TYPE_NAVIRE;

typedef enum TypeNavire{
    NAVIRE_ALL,             // = 0  
    NAVIRE_PASSAGERS,       // = 1  
    NAVIRE_MARCHANDISES,    // = 2  
    NAVIRE_PETROLIER,       // = 3  
    NAVIRE_YACHT            // = 4  
}TypeNavire;

typedef struct Navire{
    char* nom;
    int id;
    TypeNavire type;
    char etat[SIZE];            // (en mer, accosté, en attente)
    int CapaciteChargement;     // (en tonnes)
    struct Navire* NextNavire;
}Navire;

typedef struct Quai{
    char nom[SIZE];
    int NumeroQuai;
    //int QuaiSize; //en mêtres
    int Profondeur;
    TypeNavire Type;
    int NbNaviresAccostes;
    struct Navire* NextNavire;     //Liste chaînée des navires en attente d'accostage
}Quai;

typedef struct Port{
    Quai* QuaiPassager;     // place par quai : 4
    Quai* QuaiMarchand;     // place par quai : 3
    Quai* QuaiPetrolier;    // place par quai : 1
    Quai* QuaiYacht;        // place par quai : 3
    Quai* QuaiMouillage;    // place par quai : 5 (a voir)
}Port;

Port* initQuai();
Quai* CreerQuai(Quai* quai);
Navire* CreerNavire(Navire* navire);
void AfficherQuai(Port* port);
void AfficherNavire(Navire* navire);
void AjouterFinListeQuai(Quai* quai, Quai* new);
void AjouterFinListeNavire(Navire* navire, Navire* new);

#endif