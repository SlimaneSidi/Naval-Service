#include "../include/func.h"

Quai* CreerQuai(Quai* quai){
    Quai* quai1 = malloc(sizeof(Quai));
    if(quai1 == NULL) {return NULL;}

    printf("Choisissez le numéro du quai : ");
    if (scanf("%d", &quai1->NumeroQuai) != 1) {
        free(quai1);
        printf("\n\n");
        return NULL;
    }
    printf("Choisissez la taille du quai : ");
    if (scanf("%d", &quai1->QuaiSize) != 1) {
        free(quai1);
        printf("\n\n");
        return NULL;
    }
    printf("Choisissez la profondeur du quai : ");
    if (scanf("%d", &quai1->Profondeur) != 1) {
        free(quai1);
        printf("\n\n");
        return NULL;
    }
    printf("Choisissez le type de navire : (NavirePassagers, NavireMarchand, Petrolier, ou Yacht)");
    char typeTemp[SIZE];
    if (scanf("%s", typeTemp) != 1) {
        free(quai1);
        printf("\n\n");
        return NULL;
    }

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
        free(quai1);
        return NULL;
    }
    printf("Choisissez le nombre maximum de navires accostés : ");
    if (scanf("%d", &quai1->MaxNaviresAccostés) != 1) {
        free(quai1);
        printf("\n\n");
        return NULL;
    }

    quai1->NextNavire = NULL;
    return quai1;
}

Navire* CreerNavire(Navire* navire)
{
    Navire* navire1 = malloc(sizeof(Navire));
    if (navire1 == NULL) {return NULL;}

    printf("Choisissez l'identifiant du navire : ");
    if (scanf("%d", &navire1->id) != 1) {
        free(navire1);
        printf("\n\n");
        return NULL;
    }
    printf("Choisissez le type de navire (NavirePassagers, NavireMarchand, Petrolier, ou Yacht) : ");
    char typeTemp[SIZE];
    if (scanf("%s", typeTemp) != 1) {
        free(navire1);
        printf("\n\n");
        return NULL;
    }

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
        free(navire1);
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
        free(navire1);
        printf("\n\n");
        return NULL;
    }
    printf("Choisissez la capacité de chargement du navire : ");
    if (scanf("%d", &navire1->CapaciteChargement) != 1) {
        free(navire1);
        printf("\n\n");
        return NULL;
    }

    return navire1;
}

void AfficherQuai(Quai* quai)
{
    printf("Numéro du quai : %d\n",quai->NumeroQuai);
    printf("Taille du quai : %d\n",quai->QuaiSize);
    printf("Profondeur du quai : %d\n",quai->Profondeur);
    //printf("Type de navire : %s\n",quai->TypeNavire);
    printf("Nombre maximum de navires accostés : %d\n",quai->MaxNaviresAccostés);
}

void AfficherNavire(Navire* navire)
{
    printf("Identifiant du navire : %d\n",navire->id);
    //printf("Type de navire : %s\n",navire->type);
    printf("Etat du navire : %s\n",navire->etat);
    printf("Capacité de chargement du navire : %d\n",navire->CapaciteChargement);
}