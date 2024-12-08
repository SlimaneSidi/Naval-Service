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

int DrawNB;
Port* port = NULL;

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
    couleurCourante(200, 200, 200);
    rectangle(button->x, button->y, button->x + button->width, button->y + button->height);
    couleurCourante(0, 0, 0);
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
    static bool pleinEcran = false;          
    static DonneesImageRGB *image = NULL; 
    static Button* bouton1 = NULL;
    static Button* bouton2 = NULL;
    static Button* bouton3 = NULL;
    static Button* bouton4 = NULL;
	static Button* bouton5 = NULL;
	static Button* bouton6 = NULL;
    static Button* bouton7 = NULL;
    
    switch (evenement) {
    case Initialisation:
        image = lisBMPRGB("data/img/sky2.bmp");
        bouton1 = initializeButton(50, 50, "Jouer");
        bouton2 = initializeButton(200, 50, "Quitter");
        bouton3 = initializeButton(25, 500, "Afficher quai");
        bouton4 = initializeButton(25, 440, "Afficher navires");
        bouton5 = initializeButton(25, 380, "Cree navire");
		bouton6 = initializeButton(25, 370, "distribution");
        bouton7 = initializeButton(25, 210, "Quitter");
        port = initQuai(); 
        demandeTemporisation(20);
        break;
    case Temporisation:
        break;
    case Affichage:
        switch (DrawNB) {
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
			drawButton(bouton6);
            break;
        }
        break;
    case Clavier:
        switch (caractereClavier()) {
        case 'Q':
        case 'q':
            libereDonneesImageRGB(&image); 
            termineBoucleEvenements();
            break;
        case 'F':
        case 'f':
            pleinEcran = !pleinEcran;
            if (pleinEcran)
                modePleinEcran();
            else
                redimensionneFenetre(LargeurFenetre, HauteurFenetre);
            break;
        case 'R':
        case 'r':
            demandeTemporisation(20);
            break;
        case 'L':
        case 'l':
            demandeTemporisation(100);
            break;
        case 'S':
        case 's':
            break;
        case 'W':
        case 'w':
            changeSquareColor(0, 0, 0, 255, 0);
            demandeTemporisation(20);
            rafraichisFenetre();
            break;
        case 'X':
        case 'x':
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
            changeSquareColor(1, 1, 200, 255, 0);
            if (etatBoutonSouris() == GaucheAppuye) {
                int mouseX = abscisseSouris();
                int mouseY = ordonneeSouris();
                if (DrawNB == 6) { 
                    if (isButtonClicked(bouton1, mouseX, mouseY) == 1) {
                        printf("Button jouer\n");
                    }
                    if (isButtonClicked(bouton2, mouseX, mouseY) == 1) {
                        printf("Button quitter\n");
                        libereDonneesImageRGB(&image); 
                        termineBoucleEvenements();
                    }
                }
                if (DrawNB == 9) { 
                    if (isButtonClicked(bouton3, mouseX, mouseY) == 1) {
                        printf("\n\n");
                        AfficherQuai(port); 
                    }
                    if (isButtonClicked(bouton4, mouseX, mouseY) == 1) {
                        printf("\n\n");
                        printf("Affichage des navires:\n");
                        AfficherNavire(navire1);
                    }
                    if (isButtonClicked(bouton5, mouseX, mouseY) == 1) {
                        printf("Créer un navire :\n");
                        GenererBateaux(port, &navire1, 0);
                    }
					 if (isButtonClicked(bouton6, mouseX, mouseY) == 1) {
                        printf("Distribution :\n");
                        GestionMouillage(port, navire1);
                    }
                    if (isButtonClicked(bouton7, mouseX, mouseY) == 1) {
                        printf("Button quitter\n");
                        libereDonneesImageRGB(&image); 
                        termineBoucleEvenements();
                    }
                }
            }
            rafraichisFenetre();
            break;
        case GaucheRelache:
            break;
        case DroiteAppuye:
        case DroiteRelache:
            break;
        case MilieuAppuye:
        case MilieuRelache:
            break;
        case ScrollDown:
            break;
        case ScrollUp:
            break;
        case ScrollRight:
            break;
        case ScrollLeft:
            break;
        }
        break;
    case Souris:
        break;
    case Inactivite: 
        break;
    case Redimensionnement: 
        printf("Largeur : %d\t", largeurFenetre());
        printf("Hauteur : %d\n", hauteurFenetre());
        break;
    }
}