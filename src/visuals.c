#include "../lib/gfxlib/GfxLib.h"
#include "../include/visuals.h"
#include "../lib/gfxlib/BmpLib.h"
#include "../include/ourdrawings.h"
extern Button myButton;

int DrawNB;

int InitGFXMain(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("OpenGL", LargeurFenetre, HauteurFenetre);
	lanceBoucleEvenements();
	return 0;
}

int GetDrawNB(int NB)
{
	DrawNB = NB;
	return DrawNB;
}

void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 20; 
	const double PasAngulaire = 2. * M_PI / Pas;
	int index;

	for (index = 0; index < Pas; ++index) 
	{
		const double angle = 2. * M_PI * index / Pas; 
		triangle(centreX, centreY,
				 centreX + rayon * cos(angle), centreY + rayon * sin(angle),
				 centreX + rayon * cos(angle + PasAngulaire), centreY + rayon * sin(angle + PasAngulaire));
		
	}
}

void gestionEvenement(EvenementGfx evenement)
{

	static bool pleinEcran = false;		  // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran

	switch (evenement)
	{
	case Initialisation:

		image = lisBMPRGB("data/img/sky2.bmp");
		initializeButton();
		demandeTemporisation(20);
		break;

	case Temporisation:

		break;

	case Affichage:

		
		switch (DrawNB)
		{ // On dessine en fonction de la valeur de DrawNB
		case 6:
			Draw1();
			break;
		
		case 7:
			Draw2();
			break;

		case 8:
			
             initializeSquares();
             changeSquareColor(3, 0, 0, 255, 0);
			 changeSquareColor(4, 1, 0, 255, 0);
			 Draw3();
			break;
		}

		break;

	case Clavier:
		printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

		switch (caractereClavier())
		{
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
		switch (etatBoutonSouris())
		{
		case GaucheAppuye:
			printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
			changeSquareColor(1, 1, 200, 255, 0);
			 if (etatBoutonSouris() == GaucheAppuye) {
				//Button myButton;
                int mouseX = abscisseSouris();
                int mouseY = ordonneeSouris();
                if (isButtonClicked(Button myButton, mouseX, mouseY)) {
                    printf("Button clicked!\n");
				}
			 }
			rafraichisFenetre();
			// Si le bouton gauche de la souris est appuye, faire repartir
			// la balle de la souris

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





