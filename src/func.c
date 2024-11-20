#include "../include/func.h"

Quai* CreerQuai(Quai* quai){
    Quai* quai1 = malloc(sizeof(Quai));
    //if(quai1 == NULL) {return NULL;}

    printf("Choisissez le numéro du quai : ");
    //if ( != 1) {
    scanf("%d", &quai1->NumeroQuai);
    //free(quai1);
    printf("\n\n");
    //return NULL;
    
    printf("Choisissez la taille du quai : ");
    scanf("%d", &quai1->QuaiSize);
    printf("\n\n");
    
    printf("Choisissez la profondeur du quai : ");
    scanf("%d", &quai1->Profondeur);
    printf("\n\n");
    
    printf("Choisissez le type de navire (NavirePassagers, NavireMarchand, Petrolier, ou Yacht) : ");
    char typeTemp[SIZE];
    scanf("%s", typeTemp);
    printf("\n\n");

    if (strcmp(typeTemp, "NavirePassagers") == 0) {
        quai1->TypeNavire[0] = &(TYPE_NAVIRE) { .NavirePassagers = "NavirePassagers" };
    } else if (strcmp(typeTemp, "NavireMarchand") == 0) {
        quai1->TypeNavire[0] = &(TYPE_NAVIRE) { .NavireMarchand = "NavireMarchand" };
    } else if (strcmp(typeTemp, "Petrolier") == 0) {
        quai1->TypeNavire[0] = &(TYPE_NAVIRE) { .Petrolier = "Petrolier" };
    } else if (strcmp(typeTemp, "Yacht") == 0) {
        quai1->TypeNavire[0] = &(TYPE_NAVIRE) { .Yacht = "Yacht" };
    } else {
        printf("Type de navire invalide.\n");
        return NULL;
    }
    printf("Choisissez le nombre maximum de navires accostés : ");
    scanf("%d", &quai1->MaxNaviresAccostés);
    printf("\n\n");

    quai1->NextNavire = NULL;
    quai1 = quai;
    return quai;
}

Navire* CreerNavire(Navire* navire)
{
    Navire* navire1 = malloc(sizeof(Navire));
    //if (navire1 == NULL) {return NULL;}

    printf("Choisissez l'identifiant du navire : ");
    scanf("%d", &navire1->id);
    printf("\n\n");

    printf("Choisissez le type de navire (NavirePassagers, NavireMarchand, Petrolier, ou Yacht) : ");
    char typeTemp[SIZE];
    scanf("%s", typeTemp);
    printf("\n\n");

    if (strcmp(typeTemp, "NavirePassagers") == 0) {
        navire1->type[0] = &(TYPE_NAVIRE) { .NavirePassagers = "NavirePassagers" };
    } else if (strcmp(typeTemp, "NavireMarchand") == 0) {
        navire1->type[0] = &(TYPE_NAVIRE) { .NavireMarchand = "NavireMarchand" };
    } else if (strcmp(typeTemp, "Petrolier") == 0) {
        navire1->type[0] = &(TYPE_NAVIRE) { .Petrolier = "Petrolier" };
    } else if (strcmp(typeTemp, "Yacht") == 0) {
        navire1->type[0] = &(TYPE_NAVIRE) { .Yacht = "Yacht" };
    } else {
        printf("Type de navire invalide.\n");
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
    printf("Choisissez la capacité de chargement du navire : ");
    scanf("%d", &navire1->CapaciteChargement);
    printf("\n\n");

    navire1 = navire;
    return navire;
}

void AfficherQuai(Quai* quai)
{
    if (quai == NULL) {
        printf("Quai non initialisé.\n");
        return;
    }
    printf("Numéro du quai : %d\n",quai->NumeroQuai);
    printf("Taille du quai : %d\n",quai->QuaiSize);
    printf("Profondeur du quai : %d\n",quai->Profondeur);
    //printf("Type de navire : %s\n",quai->TypeNavire);
    printf("Nombre maximum de navires accostés : %d\n",quai->MaxNaviresAccostés);
}

void AfficherNavire(Navire* navire)
{
    if (navire == NULL) {
        printf("Navire non initialisé.\n");
        return;
    }
    printf("Identifiant du navire : %d\n",navire->id);
    //printf("Type de navire : %s\n",navire->type);
    printf("Etat du navire : %s\n",navire->etat);
    printf("Capacité de chargement du navire : %d\n",navire->CapaciteChargement);
}