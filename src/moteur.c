#include "../include/moteur.h"

Port* initQuai(){
    Port* port = malloc(sizeof(Port));

    port->QuaiPassager = malloc(sizeof(Quai));   // PASSAGER
    port->QuaiPassager->NumeroQuai = 1; //id
    port->QuaiPassager->Profondeur = 10;
    //port->QuaiPassager->type;
    port->QuaiPassager->NbNaviresAccostés = 4;
    port->QuaiPassager->NextNavire = NULL;

    port->QuaiMarchand = malloc(sizeof(Quai));   // MARCHAND
    port->QuaiMarchand->NumeroQuai = 2; //id
    port->QuaiMarchand->Profondeur = 10;
    //port->QuaiMarchand->type;
    port->QuaiMarchand->NbNaviresAccostés = 3;
    port->QuaiMarchand->NextNavire = NULL;

    port->QuaiPetrolier = malloc(sizeof(Quai));   // PETROLIER
    port->QuaiPetrolier->NumeroQuai = 3; //id
    port->QuaiPetrolier->Profondeur = 10;
    //port->QuaiPetrolier->type;
    port->QuaiPetrolier->NbNaviresAccostés = 1;
    port->QuaiPetrolier->NextNavire = NULL;

    port->QuaiYacht = malloc(sizeof(Quai));   // YACHT
    port->QuaiYacht->NumeroQuai = 4; //id
    port->QuaiYacht->Profondeur = 10;
    //port->QuaiYacht->type;
    port->QuaiYacht->NbNaviresAccostés = 3;
    port->QuaiYacht->NextNavire = NULL;

    port->QuaiMouillage = malloc(sizeof(Quai));  // MOUILLAGE
    port->QuaiMouillage->NumeroQuai = 0; //id
    port->QuaiMouillage->Profondeur = 10;
    //port->QuaiMouillage->type;
    port->QuaiMouillage->NbNaviresAccostés = 0;
    port->QuaiMouillage->NextNavire = NULL;

    return port;
}

Navire* CreerNavire(Navire* navire){
    Navire* navire1 = malloc(sizeof(Navire));
    //if (navire1 == NULL) {return NULL;}

    printf("Choisissez l'identifiant du navire : ");
    scanf("%d", &navire1->id);
    printf("\n");

    printf("Choisissez le type de navire (NavirePassager (1), NavireMarchand (2), Petrolier (3), ou Yacht (4)) : ");
    int typeTemp;
    scanf("%d", &typeTemp);
    if (typeTemp == 1) {
        printf(navire1->type, "navire de passagers");
    } else if (typeTemp == 2) {
        printf(navire1->type, "navire de marchandises");
    } else if (typeTemp == 3) {
        printf(navire1->type, "pétrolier");
    } else if (typeTemp == 4) {
        printf(navire1->type, "yacht");
    } else {
        printf("\n\n");
        return NULL;
    }
    
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
    
    printf("Numéro du quai : %d\n",port1->QuaiPassager->NumeroQuai);   // PASSAGER
    //printf("Taille du quai : %d\n",port1->QuaiPassager->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiPassager->Profondeur);
    printf("Type de navire : %d\n",port1->QuaiPassager->Type); 
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiPassager->NbNaviresAccostés);

    printf("Numéro du quai : %d\n",port1->QuaiMarchand->NumeroQuai);   // MARCHAND
    //printf("Taille du quai : %d\n",port1->QuaiMarchand->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiMarchand->Profondeur);
    printf("Type de navire : %d\n",port1->QuaiMarchand->Type); 
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiMarchand->NbNaviresAccostés);

    printf("Numéro du quai : %d\n",port1->QuaiPetrolier->NumeroQuai);   // PETROLIER
    //printf("Taille du quai : %d\n",port1->QuaiPetrolier->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiPetrolier->Profondeur);
    printf("Type de navire : %d\n",port1->QuaiPetrolier->Type); 
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiPetrolier->NbNaviresAccostés);

    printf("Numéro du quai : %d\n",port1->QuaiYacht->NumeroQuai);   // YACHT
    //printf("Taille du quai : %d\n",port1->QuaiYacht->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiYacht->Profondeur);
    printf("Type de navire : %d\n",port1->QuaiYacht->Type); 
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiYacht->NbNaviresAccostés);

    printf("Numéro du quai : %d\n",port1->QuaiMouillage->NumeroQuai);  // MOUILLAGE
    //printf("Taille du quai : %d\n",port1->QuaiMouillage->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiMouillage->Profondeur);
    printf("Type de navire : %d\n",port1->QuaiMouillage->Type); 
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiMouillage->NbNaviresAccostés);
    
}

void AfficherNavire(Navire* navire){
    Navire* navire1 = navire;
    //while (navire1 != NULL) {
    printf("Identifiant du navire : %d\n",navire1->id);
    printf("Type de navire : %s\n",navire1->type); // NE FONCTIONNE PAS
    printf("Etat du navire : %s\n",navire1->etat);
    printf("Capacité de chargement du navire : %d\n",navire1->CapaciteChargement);
    //}
}

void AjouterFinListeNavire(Navire* navire, Navire* new) {
    if (navire == NULL) {navire = new; return;}
    Navire* current = navire;
    while (current->NextNavire != NULL) {current = current->NextNavire;}
    current->NextNavire = new;
    new->NextNavire = NULL;
}