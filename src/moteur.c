#include "../include/moteur.h"
#include "../include/nomBateaux.h"

const char* TypeNavireToString(TypeNavire type) {
    switch (type) {
        case NAVIRE_PASSAGERS: return "Navire de passagers";
        case NAVIRE_MARCHANDISES: return "Navire de marchandises";
        case NAVIRE_PETROLIER: return "Pétrolier";
        case NAVIRE_YACHT: return "Yacht";
        default: return "Inconnu"; }
}

Port* initQuai(){
    Port* port = malloc(sizeof(Port));

    port->QuaiPassager = malloc(sizeof(Quai));   // PASSAGER
    strcpy(port->QuaiPassager->nom, "Quai de navires passagers");
    port->QuaiPassager->NumeroQuai = 1; //id
    port->QuaiPassager->Profondeur = 10;
    port->QuaiPassager->Type = NAVIRE_PASSAGERS;
    port->QuaiPassager->NbNaviresAccostes = 4;
    port->QuaiPassager->NextNavire = NULL;

    port->QuaiMarchand = malloc(sizeof(Quai));   // MARCHAND
    strcpy(port->QuaiMarchand->nom, "Quai de navires marchands");
    port->QuaiMarchand->NumeroQuai = 2; //id
    port->QuaiMarchand->Profondeur = 10;
    port->QuaiMarchand->Type = NAVIRE_MARCHANDISES;
    port->QuaiMarchand->NbNaviresAccostes = 3;
    port->QuaiMarchand->NextNavire = NULL;

    port->QuaiPetrolier = malloc(sizeof(Quai));   // PETROLIER
    strcpy(port->QuaiPetrolier->nom, "Quai de pétroliers");
    port->QuaiPetrolier->NumeroQuai = 3; //id
    port->QuaiPetrolier->Profondeur = 10;
    port->QuaiPetrolier->Type = NAVIRE_PETROLIER;
    port->QuaiPetrolier->NbNaviresAccostes = 1;
    port->QuaiPetrolier->NextNavire = NULL;

    port->QuaiYacht = malloc(sizeof(Quai));   // YACHT
    strcpy(port->QuaiYacht->nom, "Quai de yachts");
    port->QuaiYacht->NumeroQuai = 4; //id
    port->QuaiYacht->Profondeur = 10;
    port->QuaiYacht->Type = NAVIRE_YACHT;
    port->QuaiYacht->NbNaviresAccostes = 3;
    port->QuaiYacht->NextNavire = NULL;

    port->QuaiMouillage = malloc(sizeof(Quai));  // MOUILLAGE
    strcpy(port->QuaiMouillage->nom, "Quai de mouillage");
    port->QuaiMouillage->NumeroQuai = 0; //id
    port->QuaiMouillage->Profondeur = 10;
    port->QuaiMouillage->Type = NAVIRE_ALL;
    port->QuaiMouillage->NbNaviresAccostes = 4;
    port->QuaiMouillage->NextNavire = NULL;

    return port;
}

void AjouterFinListeNavire(Navire* navire, Navire* new) {
    if (navire == NULL) {navire = new; return;}
    Navire* current = navire;
    while (current->NextNavire != NULL) {current = current->NextNavire;}
    current->NextNavire = new;
    new->NextNavire = NULL;
}

Navire* CreerNavire(Navire* navire) {
    static int id_counter = 1; // ID du navire
    Navire* navire1 = malloc(sizeof(Navire));

    const char* nomAleatoire = choisirNomAleatoire(nomsBateaux, 40);
    navire1->nom = malloc(strlen(nomAleatoire) + 1);
    strcpy(navire1->nom, nomAleatoire);
    printf("Nom du navire : %s\n\n",navire1->nom);
    navire1->id = id_counter++;
    printf("Identifiant du navire : %d\n\n",navire1->id);
    printf("Choisissez le type de navire (NavirePassager (1), NavireMarchand (2), Petrolier (3), ou Yacht (4)) : ");
    int typeTemp;
    scanf("%d", &typeTemp);
    if (typeTemp == 1) {
        navire1->type = NAVIRE_PASSAGERS;
    } else if (typeTemp == 2) {
        navire1->type = NAVIRE_MARCHANDISES;
    } else if (typeTemp == 3) {
        navire1->type = NAVIRE_PETROLIER;
    } else if (typeTemp == 4) {
        navire1->type = NAVIRE_YACHT;
    } else {
        printf("\n\n");
        return NULL;
    }
    printf("\n");
    
    printf("Choisissez l'état du navire (en mer (1), accosté (2), en attente (3)) : ");
    int etatTemp;
    scanf("%d", &etatTemp);
    if (etatTemp == 1) {
        strcpy(navire1->etat, "en mer");
    } else if (etatTemp == 2) {
        strcpy(navire1->etat, "accosté");
    } else if (etatTemp == 3) {
        strcpy(navire1->etat, "en attente");
    } else {
        printf("\n\n");
        return NULL;
    }
    printf("\n");
    printf("Choisissez la capacité de chargement du navire : ");
    scanf("%d", &navire1->CapaciteChargement);
    printf("\n");

    return navire1;
}

void AfficherQuai(Port* port){
    Port* port1 = port;

    printf("-- %s : \n",port1->QuaiPassager->nom);
    printf("Numéro du quai : %d\n",port1->QuaiPassager->NumeroQuai);   // PASSAGER
    //printf("Taille du quai : %d\n",port1->QuaiPassager->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiPassager->Profondeur);
    printf("Type de navire : %s\n",TypeNavireToString(port1->QuaiPassager->Type)); 
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiPassager->NbNaviresAccostes);

    printf("-- %s : \n",port1->QuaiMarchand->nom);
    printf("Numéro du quai : %d\n",port1->QuaiMarchand->NumeroQuai);   // MARCHAND
    //printf("Taille du quai : %d\n",port1->QuaiMarchand->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiMarchand->Profondeur);
    printf("Type de navire : %s\n",TypeNavireToString(port1->QuaiMarchand->Type)); 
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiMarchand->NbNaviresAccostes);

    printf("-- %s : \n",port1->QuaiPetrolier->nom);
    printf("Numéro du quai : %d\n",port1->QuaiPetrolier->NumeroQuai);   // PETROLIER
    //printf("Taille du quai : %d\n",port1->QuaiPetrolier->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiPetrolier->Profondeur);
    printf("Type de navire : %s\n",TypeNavireToString(port1->QuaiPetrolier->Type)); 
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiPetrolier->NbNaviresAccostes);

    printf("-- %s : \n",port1->QuaiYacht->nom);
    printf("Numéro du quai : %d\n",port1->QuaiYacht->NumeroQuai);   // YACHT
    //printf("Taille du quai : %d\n",port1->QuaiYacht->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiYacht->Profondeur);
    printf("Type de navire : %s\n",TypeNavireToString(port1->QuaiYacht->Type));
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiYacht->NbNaviresAccostes);

    printf("-- %s : \n",port1->QuaiMouillage->nom);
    printf("Numéro du quai : %d\n",port1->QuaiMouillage->NumeroQuai);  // MOUILLAGE
    //printf("Taille du quai : %d\n",port1->QuaiMouillage->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiMouillage->Profondeur);
    printf("Type de navire : %s\n",TypeNavireToString(port1->QuaiMouillage->Type));
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiMouillage->NbNaviresAccostes);
}

void AfficherNavire(Navire* navire){
    if (navire == NULL) {printf("Aucun navire n'a été créé\n"); return;}
    Navire* navire1 = navire;
    while (navire1 != NULL) {
        printf("Nom du navire : %s\n",navire1->nom);
        printf("Identifiant du navire : %d\n",navire1->id);
        printf("Type de navire : %s\n",TypeNavireToString(navire1->type));
        printf("Etat du navire : %s\n",navire1->etat);
        printf("Capacité de chargement du navire : %d\n",navire1->CapaciteChargement);
        printf("\n");
        navire1 = navire1->NextNavire;
    }
}