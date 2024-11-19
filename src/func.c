#include "../include/func.h"

Quai CreerQuai(Quai *quai)
{
    Quai *quai1 = malloc(sizeof(Quai));
    if(quai1 == NULL) {return;}

    printf("Choisissez le numéro du quai : \n\n");
    scanf("%d",&quai1->NumeroQuai);
    printf("Choisissez la taille du quai : \n\n");
    scanf("%d",&quai1->QuaiSize);
    printf("Choisissez la profondeur du quai : \n\n");
    scanf("%d",&quai1->Profondeur);
    printf("Choisissez le type de navire : (Navire de passagers, navire de marchandises, pétrolier, ou yacht)\n\n");
    scanf("%s",quai1->TypeNavire);
    printf("Choisissez le nombre maximum de navires accostés : \n\n");
    scanf("%d",&quai1->MaxNaviresAccostés);
    quai1->NextNavire = NULL;
    return *quai1;
}

Navire CreerNavire(Navire *navire)
{
    Navire *navire1 = malloc(sizeof(Navire));
    if(navire1 == NULL) {return;}

    printf("Choisissez l'identifiant du navire : \n\n");
    scanf("%d",&navire1->id);
    printf("Choisissez le type de navire : (Navire de passagers, navire de marchandises, pétrolier, ou yacht)\n\n");
    scanf("%s",&navire1->type);
    printf("Choisissez l'état du navire : (en mer, accosté, en attente)\n\n");
    scanf("%s",&navire1->etat);
    printf("Choisissez la capacité de chargement du navire : \n\n");
    scanf("%d",&navire1->CapaciteChargement);
    return *navire1;
}

void AfficherQuai(Quai *quai)
{
    printf("Numéro du quai : %d\n",quai->NumeroQuai);
    printf("Taille du quai : %d\n",quai->QuaiSize);
    printf("Profondeur du quai : %d\n",quai->Profondeur);
    printf("Type de navire : %s\n",quai->TypeNavire);
    printf("Nombre maximum de navires accostés : %d\n",quai->MaxNaviresAccostés);
}

void AfficherNavire(Navire *navire)
{
    printf("Identifiant du navire : %d\n",navire->id);
    printf("Type de navire : %s\n",navire->type);
    printf("Etat du navire : %s\n",navire->etat);
    printf("Capacité de chargement du navire : %d\n",navire->CapaciteChargement);
}