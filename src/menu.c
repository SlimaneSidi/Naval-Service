#include "../include/menu.h"
#include "../include/moteur.h"
#include "../include/nomBateaux.h"

void menu(Port* port, Navire* navire){
    int i = 1;
    //Navire* navire1 = malloc(sizeof(Navire));
    printf("\n");
    printf("-----------------LOGICIEL-NAVAL-SERVICE------------------\n\n");

    while(i != 0){
        printf("----- QUE VOULEZ VOUS FAIRE ? -----\n\n");
        printf("1 - Créer un navire\n");
        printf("2 - Afficher les quais\n");
        printf("3 - Afficher les navires\n");
        printf("0 - Quitter\n\n");

        int choix = 0; 
        scanf("%d",&choix);

        switch(choix){
        case 0 :   // QUITTER
            i = 0;
            break;
        case 1 : 
            printf("\n");
            printf("--- Créer un navire ---\n\n");
            choisirNomAleatoire(nomsBateaux, TAILLE);
            Navire* newNavire = CreerNavire(NULL); // Crée un nouveau navire
            AjouterFinListeNavire(navire, newNavire); // Ajoute le navire à la liste
            if (navire == NULL) {
                navire = newNavire; // Si la liste était vide, on met à jour la tête
            }
            //navire = CreerNavire(navire);
            printf("\n\n");
            break;
        case 2 : 
            printf("\n");
            printf("--- Afficher les quais ---\n\n");
            AfficherQuai(port);
            printf("\n\n");
            break;
        case 3 : 
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