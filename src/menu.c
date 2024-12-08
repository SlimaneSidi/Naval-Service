#include "../include/menu.h"
#include "../include/moteur.h"
#include "../include/nomBateaux.h"
#include "../include/save.h"
#include "../include/visuals.h"

void menu(Port* port, Navire* navire){
    int argc = 0; char **argv = NULL;
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
        printf("8 - dessiner bateau2\n");
        printf("9 - dessiner map\n");
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
                    int GAME = 1;
                    int JOUER = 0;
                    int AJOUTERBATEAU = 0;
                    while (GAME == 1){
                        // APPEL DU MENU GFX
                    
                        // mettre le bouton ici
                        printf("Nouveau navire arrivant :\n");
                        if (AJOUTERBATEAU == 1) {
                            genererBateaux(port, navire, AJOUTERBATEAU);}
                        

                    }
                    break;
                case 2:
                    ChargerNavalService("sauvegarde.bin");
                    //AfficherSauvegarde("sauvegarde.bin");
                    break;
                default:
                    printf("Choix invalide\n");
                    break;
            printf("\n\n");
            }
            break;
            
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
            printf("\n");
            printf("--- Dessiner bateau ---\n\n");
            printf("\n\n");
            GetDrawNB(6);
            InitGFXMain(argc, argv);
            break;
        case 8 :
            printf("\n");
            printf("--- Dessiner bateau 2  ---\n\n");
            printf("\n\n");
            GetDrawNB(7);
            InitGFXMain(argc, argv);
            break;
        case 9 :
            printf("\n");
            printf("--- Dessiner Map  ---\n\n");
            printf("\n\n");
            GetDrawNB(8);
            InitGFXMain(argc, argv);
            break;
        default:
        printf("error");
        }
    }
}