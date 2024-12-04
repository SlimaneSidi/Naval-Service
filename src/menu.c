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
        printf("1 - Lancer\n");
        printf("2 - Créer un navire manuellement\n");
        printf("3 - Créer un navire aléatoire\n");
        printf("4 - Afficher les quais\n");
        printf("5 - Afficher les navires\n");
        printf("6 - Sauvegarder les quais et les navires\n");
        printf("7 - dessiner bateau\n");
        printf("0 - Quitter\n\n");

        int choix = 0; 
        int choixSave = 0;
        scanf("%d",&choix);

        switch(choix){
        case 0 :   // QUITTER
            i = 0;
            break;
        case 1 :   // LANCER
            printf("\n");
            printf("--- Lancement du logiciel naval service ---\n\n");
            printf("1 - Lancer le programme sans sauvegarde\n");
            printf("2 - Chercher une sauvegarde\n");
            scanf("%d",&choixSave);
            switch(choixSave){
                case 1:
                    Navire* newNavireAleatoire1 = CreerNavireAleatoire(NULL);
                    AjouterFinListeNavire(navire, newNavireAleatoire1, port);
                    if (navire == NULL) {
                        navire = newNavireAleatoire1;
                    }
                    Navire* newNavireAleatoire2 = CreerNavireAleatoire(NULL);
                    AjouterFinListeNavire(navire, newNavireAleatoire2, port);
                    if (navire == NULL) {
                        navire = newNavireAleatoire2;
                    }
                    AfficherNavire(navire);
                    break;
                case 2:
                    ChargerNavalService("sauvegarde.bin");
                    AfficherSauvegarde("sauvegarde.bin");
                    break;
            printf("\n\n");
            break;
            }
        case 2 : 
            printf("\n");
            printf("--- Créer un navire manuellement ---\n\n");
            choisirNomAleatoire(nomsBateaux, TAILLE);
            Navire* newNavire = CreerNavire(NULL); 
            AjouterFinListeNavire(navire, newNavire, port);
            if (navire == NULL) {
                navire = newNavire;
            }
            printf("\n\n");
            break;
        case 3 :
            printf("\n");
            printf("--- Créer un navire aléatoire ---\n\n");
            Navire* newNavireAleatoire = CreerNavireAleatoire(NULL);
            AjouterFinListeNavire(navire, newNavireAleatoire, port);
            if (navire == NULL) {
                navire = newNavireAleatoire;
            }
            printf("\n\n");
            break;
        case 4 : 
            printf("\n");
            printf("--- Afficher les quais ---\n\n");
            AfficherQuai(port);
            printf("\n\n");
            break;
        case 5 : 
            printf("\n");
            printf("--- Afficher les navires ---\n\n");
            AfficherNavire(navire);
            printf("\n\n");
            break;
        case 6 :
            printf("\n");
            printf("--- Sauvegarde effectuée ---\n\n");
            saveNavalService(navire, "sauvegarde.bin");
            AfficherSauvegarde("sauvegarde.bin");
            printf("\n");
            break;
        case 7 :
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