#include "../include/func.h"

Quai* CreerQuai(Quai* quai){
    Quai* quai1 = malloc(sizeof(Quai));

    printf("Choisissez le numéro du quai : ");
    scanf("%d", &quai1->NumeroQuai);
    printf("\n");
    
    printf("Choisissez la taille du quai : ");
    scanf("%d", &quai1->QuaiSize);
    printf("\n");
    
    printf("Choisissez la profondeur du quai : ");
    scanf("%d", &quai1->Profondeur);
    printf("\n");
    
    printf("Choisissez le type de navire (NavirePassager, NavireMarchand, Petrolier, ou Yacht) : ");
    char typeTemp[SIZE];
    scanf("%s", typeTemp);
    printf("\n");

    if (strcmp(typeTemp, "NavirePassager") == 0) {
        quai1->TypeNavire[0] = &(TYPE_NAVIRE) { .NavirePassagers = "NavirePassager" };
    } else if (strcmp(typeTemp, "NavireMarchand") == 0) {
        quai1->TypeNavire[0] = &(TYPE_NAVIRE) { .NavireMarchand = "NavireMarchand" };
    } else if (strcmp(typeTemp, "Petrolier") == 0) {
        quai1->TypeNavire[0] = &(TYPE_NAVIRE) { .Petrolier = "Petrolier" };
    } else if (strcmp(typeTemp, "Yacht") == 0) {
        quai1->TypeNavire[0] = &(TYPE_NAVIRE) { .Yacht = "Yacht" };
    } else {
        printf("Type de navire invalide.\n");
        CreerQuai(quai);
    }
    printf("Choisissez le nombre maximum de navires accostés : ");
    scanf("%d", &quai1->MaxNaviresAccostés);
    printf("\n");

    quai1->NextNavire = NULL;
    printf("Quai : %d\n", quai1->NumeroQuai);
    return quai1;
}

Navire* CreerNavire(Navire* navire){
    Navire* navire1 = malloc(sizeof(Navire));
    //if (navire1 == NULL) {return NULL;}

    printf("Choisissez l'identifiant du navire : ");
    scanf("%d", &navire1->id);
    printf("\n");

    printf("Choisissez le type de navire (NavirePassager, NavireMarchand, Petrolier, ou Yacht) : ");
    char typeTemp[SIZE];
    scanf("%s", typeTemp);
    printf("\n");

    if (strcmp(typeTemp, "NavirePassager") == 0) {
        navire1->type[0] = &(TYPE_NAVIRE) { .NavirePassagers = "NavirePassager" };
    } else if (strcmp(typeTemp, "NavireMarchand") == 0) {
        navire1->type[0] = &(TYPE_NAVIRE) { .NavireMarchand = "NavireMarchand" };
    } else if (strcmp(typeTemp, "Petrolier") == 0) {
        navire1->type[0] = &(TYPE_NAVIRE) { .Petrolier = "Petrolier" };
    } else if (strcmp(typeTemp, "Yacht") == 0) {
        navire1->type[0] = &(TYPE_NAVIRE) { .Yacht = "Yacht" };
    } else {
        printf("Type de navire invalide.\n");
        CreerNavire(navire); // Si le type de navire n'est pas valide, on recommence la création du navire (probleme pour la demande suivante faite 2 fois)
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

void AfficherQuai(Quai* quai){
    Quai* quai1 = quai;
    while (quai1 != NULL) {
        printf("Numéro du quai : %d\n",quai1->NumeroQuai);
        printf("Taille du quai : %d\n",quai1->QuaiSize);
        printf("Profondeur du quai : %d\n",quai1->Profondeur);
        //printf("Type de navire : %s\n",quai1->TypeNavire);
        printf("Nombre maximum de navires accostés : %d\n",quai1->MaxNaviresAccostés);
        quai1 = quai1->NextNavire;
    }
    printf("NULL\n");
}

void AfficherNavire(Navire* navire){
    Navire* navire1 = navire;
    while (navire1 != NULL) {
        printf("Identifiant du navire : %d\n",navire1->id);
        //printf("Type de navire : %s\n",navire1->type);
        printf("Etat du navire : %s\n",navire1->etat);
        printf("Capacité de chargement du navire : %d\n",navire1->CapaciteChargement);
    }
    printf("NULL\n");
}
