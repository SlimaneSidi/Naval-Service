#include "../include/menu.h"
#include "../include/moteur.h"
#include "../include/nomBateaux.h"
#include "../include/save.h"
#include "../include/visuals.h"

void menu(Port* port, Navire* navire){
    int i = 1;
    printf("\n");
    printf("-----------------LOGICIEL-NAVAL-SERVICE------------------\n\n");

    while(i != 0){
        printf("----- QUE VOULEZ VOUS FAIRE ? -----\n\n");
        printf("1 - Créer un navire\n");
        printf("2 - Afficher les quais\n");
        printf("3 - Afficher les navires\n");
        printf("4 - Sauvegarder les quais et les navires\n");
        printf("5 - dessiner bateau\n");
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
            Navire* newNavire = CreerNavire(NULL); 
            AjouterFinListeNavire(navire, newNavire);
            if (navire == NULL) {
                navire = newNavire;
            }
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
        case 4 :
            printf("\n");
            printf("--- Afficher la sauvegarde ---\n\n");
            saveNavalService(navire, "sauvegarde.bin");
            AfficherSauvegarde("sauvegarde.bin");
            printf("\n\n");
            break;

        case 5 :
            int argc = 0; char **argv = NULL;
            printf("\n");
            printf("--- Dessiner bateau ---\n\n");
            drawBoat(argc, argv);
            printf("\n\n");
            break;
            
        default:
        printf("error");
        }
    }
}