#include "../include/menu.h"
#include "../include/moteur.h"

void menu(Quai* quai, Navire* navire){
    int i = 1;
    printf("\n");
    printf("-----------------LOGICIEL-NAVAL-SERVICE------------------\n\n");

    while(i != 0){

        printf("----- QUE VOULEZ VOUS FAIRE ? -----\n\n");
        printf("1 - Créer un quai\n");
        printf("2 - Créer un navire\n");
        printf("3 - Afficher les quais\n");
        printf("4 - Afficher les navires\n");
        printf("0 - Quitter\n\n");

        int choix = 0; 
        scanf("%d",&choix);

        switch(choix)
        {
        case 0 :   // QUITTER
            i = 0;
            break;
        case 1 : 
            printf("\n");
            printf("--- Créer un quai ---\n\n");
            quai = CreerQuai(quai);
            printf("\n\n");
            break;
        case 2 : 
            printf("\n");
            printf("--- Créer un navire ---\n\n");
            navire = CreerNavire(navire);
            printf("\n\n");
            break;
        case 3 : 
            printf("\n");
            printf("--- Afficher les quais ---\n\n");
            AfficherQuai(quai);
            printf("\n\n");
            break;
        case 4 : 
            printf("\n");
            printf("--- Afficher les navires ---\n\n");
            AfficherNavire(navire);
            printf("\n\n");
            break;

        default:
        printf("error");
        }
    }
}