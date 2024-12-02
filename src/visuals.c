#include "../lib/gfxlib/GfxLib.h" 
#include "../include/visuals.h"
#include "../lib/gfxlib/BmpLib.h"


 int drawBoat(int argc, char **argv) {

	initialiseGfx(argc, argv);
	prepareFenetreGraphique("OpenGL", LargeurFenetre, HauteurFenetre);
    lanceBoucleEvenements();
	return 0;
}


void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 20; // Nombre de secteurs pour tracer le cercle
	const double PasAngulaire = 2.*M_PI/Pas;
	int index;
	
	for (index = 0; index < Pas; ++index) // Pour chaque secteur
	{
		const double angle = 2.*M_PI*index/Pas; // on calcule l'angle de depart du secteur
		triangle(centreX, centreY,
				 centreX+rayon*cos(angle), centreY+rayon*sin(angle),
				 centreX+rayon*cos(angle+PasAngulaire), centreY+rayon*sin(angle+PasAngulaire));
			// On trace le secteur a l'aide d'un triangle => approximation d'un cercle
	}
	
}

void gestionEvenement(EvenementGfx evenement)
{

	
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran

	/* On va aussi animer une balle traversant l'ecran */
	
	
	switch (evenement)
	{
		case Initialisation:
			
			image = lisBMPRGB("ISEN.bmp");
			demandeTemporisation(20);
			break;
		
		case Temporisation:
			
			break;
			
		case Affichage:
			
			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);
			
			// Affichage d'un rectangle "saumon"
			couleurCourante(255, 128, 128);
			rectangle((largeurFenetre()-600)/2, (hauteurFenetre()-400)/2, (largeurFenetre()-600)/2+600, (hauteurFenetre()-400)/2+400);


			////////////////////////     BATEAU    ////////////////////////////////////////
			couleurCourante(0, 0, 255);

            // Draw the hull of the boat
            ligne(200, 200, 600, 200);
            ligne(200, 200, 300, 100);
            ligne(600, 200, 500, 100);
            ligne(300, 100, 500, 100);

            // Set the color to white for the sail
            couleurCourante(255, 255, 255);

            // Draw the sail of the boat
            ligne(400, 200, 400, 400);
            ligne(400, 400, 500, 200);


            rafraichisFenetre();

			///////////////////////////////////////////////////////////////

			// Affichage d'une image
			if (image != NULL) // Si l'image a pu etre lue
			{
				// On affiche l'image
				ecrisImage((largeurFenetre()-image->largeurImage)/2, (hauteurFenetre()-image->hauteurImage)/2, image->largeurImage, image->hauteurImage, image->donneesRGB);
			}

			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir quelque peu proprement du programme */
				case 'q':
					libereDonneesImageRGB(&image); /* On libere la structure image,
					c'est plus propre, meme si on va sortir du programme juste apres */
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

