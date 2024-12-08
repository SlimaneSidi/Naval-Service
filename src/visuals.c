#include "../include/visuals.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

Navire* navire1;

Navire* InitNavire(Navire* navire) {
    navire1 = navire;
    return navire1;
}

int DrawNB; // Define the DrawNB variable
//Navire* navire = NULL; // Declare the navire variable
Port* port = NULL; // Declare the port variable

int drawBoat(int argc, char **argv) {
    initialiseGfx(argc, argv);
    prepareFenetreGraphique("OpenGL", LargeurFenetre, HauteurFenetre);
    lanceBoucleEvenements();
    return 0;
}

Button* initializeButton(int x, int y, const char* label) {
    Button* myButton = (Button*)malloc(sizeof(Button));
    myButton->x = x;
    myButton->y = y;
    myButton->width = 100;
    myButton->height = 50;
    sprintf(myButton->label, "%s", label);
    return myButton;
}

void drawButton(Button* button) {
    couleurCourante(200, 200, 200); // Set color to light gray for button background
    rectangle(button->x, button->y, button->x + button->width, button->y + button->height);
    couleurCourante(0, 0, 0); // Set color to black for text
    afficheChaine(button->label, 12, button->x + 10, button->y + 20);
}

int isButtonClicked(Button* button, int mouseX, int mouseY) {
    return mouseX >= button->x && mouseX <= button->x + button->width &&
           mouseY >= button->y && mouseY <= button->y + button->height;
}

int InitGFXMain(int argc, char **argv, Navire* navire) {
    navire1 = InitNavire(navire);
    initialiseGfx(argc, argv);
    prepareFenetreGraphique("OpenGL", LargeurFenetre, HauteurFenetre);
    lanceBoucleEvenements();
    return 0;
}

int GetDrawNB(int NB) {
    DrawNB = NB;
    return DrawNB;
}

void cercle(float centreX, float centreY, float rayon) {
    const int Pas = 20; 
    const double PasAngulaire = 2. * M_PI / Pas;
    int index;
    for (index = 0; index < Pas; ++index) {
        const double angle = 2. * M_PI * index / Pas; 
        triangle(centreX, centreY,
                 centreX + rayon * cos(angle), centreY + rayon * sin(angle),
                 centreX + rayon * cos(angle + PasAngulaire), centreY + rayon * sin(angle + PasAngulaire));
    }
}

void gestionEvenement(EvenementGfx evenement) {
    static bool pleinEcran = false;          // Pour savoir si on est en mode plein ecran ou pas
    static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran
    static Button* bouton1 = NULL;
    static Button* bouton2 = NULL;
    static Button* bouton3 = NULL;
    static Button* bouton4 = NULL;
    static Button* bouton5 = NULL;
    switch (evenement) {
    case Initialisation:
        image = lisBMPRGB("data/img/sky2.bmp");
        bouton1 = initializeButton(50, 50, "Jouer");
        bouton2 = initializeButton(200, 50, "Quitter");
        bouton3 = initializeButton(25, 500, "Afficher quai");
        bouton4 = initializeButton(25, 440, "Afficher navires");
        bouton5 = initializeButton(25, 380, "Button 5");
        port = initQuai(); // Initialize the Port object
        demandeTemporisation(20);
        break;
    case Temporisation:
        break;
    case Affichage:
        switch (DrawNB) { // On dessine en fonction de la valeur de DrawNB
        case 7:
            Draw1();
            break;
        case 8:
            Draw3();
            break;
        case 9:
            initializeSquares();
            changeSquareColor(3, 0, 0, 255, 0);
            changeSquareColor(4, 1, 0, 255, 0);
            Draw3();
            drawButton(bouton3);
            drawButton(bouton4);
            drawButton(bouton5);
            break;
        }
        break;
    case Clavier:
        printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());
        switch (caractereClavier()) {
        case 'Q': /* Pour sortir quelque peu proprement du programme */
        case 'q':
            libereDonneesImageRGB(&image); 
            termineBoucleEvenements();
            break;
        case 'F':
        case 'f':
            pleinEcran = !pleinEcran; // Changement de mode plein ecran
            if (pleinEcran)
                modePleinEcran();
            else
                redimensionneFenetre(LargeurFenetre, HauteurFenetre);
            break;
        case 'R':
        case 'r':
            // Configure le systeme pour generer un message Temporisation
            // toutes les 20 millisecondes (rapide)
            demandeTemporisation(20);
            break;
        case 'L':
        case 'l':
            // Configure le systeme pour generer un message Temporisation
            // toutes les 100 millisecondes (lent)
            demandeTemporisation(100);
            break;
        case 'S':
        case 's':
            // Configure le systeme pour ne plus generer de message Temporisation
            demandeTemporisation(-1);
            break;
        case 'W':
        case 'w':
            changeSquareColor(0, 0, 0, 255, 0);
            demandeTemporisation(20);
            rafraichisFenetre();
            break;
        case 'X':
        case 'x':
            // Configure le systeme pour ne plus generer de message Temporisation
            break;
        case 'C':
        case 'c':
            break;
        }
        break;
    case ClavierSpecial:
        printf("ASCII %d\n", toucheClavier());
        break;
    case BoutonSouris:
        switch (etatBoutonSouris()) {
        case GaucheAppuye:
            printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
            changeSquareColor(1, 1, 200, 255, 0);
            if (etatBoutonSouris() == GaucheAppuye) {
                int mouseX = abscisseSouris();
                int mouseY = ordonneeSouris();
                if (DrawNB == 6) { // Only check buttons in Draw1
                    if (isButtonClicked(bouton1, mouseX, mouseY) == 1) {
                        printf("Button jouer\n");
                    }
                    if (isButtonClicked(bouton2, mouseX, mouseY) == 1) {
                        printf("Button quitter\n");
                        libereDonneesImageRGB(&image); 
                        termineBoucleEvenements();
                    }
                }
                if (DrawNB == 9) { // Only check buttons in Draw3
                    if (isButtonClicked(bouton3, mouseX, mouseY) == 1) {
                        printf("\n\n");
                        AfficherQuai(port); // Correct function call
                    }
                    if (isButtonClicked(bouton4, mouseX, mouseY) == 1) {
                        printf("\n\n");
                        printf("Affichage des navires:\n");
                        AfficherNavire(navire1); // Display existing ships
                    }
                    if (isButtonClicked(bouton5, mouseX, mouseY) == 1) {
                        printf("Button 5 clicked\n");
                    }
                }
            }
            rafraichisFenetre();
            break;
        case GaucheRelache:
            printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
            break;
        case DroiteAppuye:
        case DroiteRelache:
            puts("Bouton droite");
            break;
        case MilieuAppuye:
        case MilieuRelache:
            puts("Bouton milieu");
            break;
        case ScrollDown:
            puts("Scroll down");
            break;
        case ScrollUp:
            puts("Scroll up");
            break;
        case ScrollRight:
            puts("Scroll right");
            break;
        case ScrollLeft:
            puts("Scroll left");
            break;
        }
        break;
    case Souris: // Si la souris est deplacee
        break;
    case Inactivite: // Quand aucun message n'est disponible
        break;
    case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
        // Donc le systeme nous en informe
        printf("Largeur : %d\t", largeurFenetre());
        printf("Hauteur : %d\n", hauteurFenetre());
        break;
    }
}

void KillWindowToDraw() {
    //libereDonneesImageRGB(image); 
    effaceFenetre(0, 200, 0);
    // lanceBoucleEvenements();
    // initializeSquares();
    // printf("Squares initialized\n");
    // changeSquareColor(3, 0, 0, 255, 0);
    // changeSquareColor(4, 1, 0, 255, 0);
    // printf("Square colors changed\n");
    // Draw3();
    // printf("Draw3 called\n");
}