#include "../lib/gfxlib/GfxLib.h" 
#include "../include/visuals.h"


void drawBoat() {
    // Initialize the graphics window
    lanceBoucleEvenements();

    // Set the color to blue for the boat
    couleurCourante(0, 0, 255);

    // Draw the hull of the boat
    ligne(200, 400, 600, 400);
    ligne(200, 400, 300, 500);
    ligne(600, 400, 500, 500);
    ligne(300, 500, 500, 500);

    // Set the color to white for the sail
    couleurCourante(255, 255, 255);

    // Draw the sail of the boat
    ligne(400, 400, 400, 200);
    ligne(400, 200, 500, 400);

    // Refresh the window to display the drawing
    rafraichisFenetre();

    // Wait for the user to press a key before closing
    termineBoucleEvenements();
}

void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran

	/* On va aussi animer une balle traversant l'ecran */
	static int xBalle;
	static int yBalle;
	static int vxBalle = 7;
	static int vyBalle = -7;
	
	switch (evenement)
	{
		case Initialisation:
			xBalle = largeurFenetre()*valeurAleatoire();
			yBalle = hauteurFenetre()*valeurAleatoire();
			image = lisBMPRGB("ISEN.bmp");
			/* Le message "Initialisation" est envoye une seule fois, au debut du
			programme : il permet de fixer "image" a la valeur qu'il devra conserver
			jusqu'a la fin du programme : soit "image" reste a NULL si l'image n'a
			pas pu etre lue, soit "image" pointera sur une structure contenant
			les caracteristiques de l'image "imageNB.bmp" */

			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);
			break;
		
		case Temporisation:
			// On met a jour les coordonnees de la balle
			xBalle += vxBalle;
			yBalle += vyBalle;

			// On fait rebondir la balle si necessaire
			if (xBalle < 0 || xBalle >= largeurFenetre())
				vxBalle = -vxBalle;
			if (yBalle < 0 || yBalle >= hauteurFenetre())
				vyBalle = -vyBalle;
			// Les coordonnees de la balle ayant eventuellement change,
			// il faut redessiner la fenetre :
			rafraichisFenetre();
			break;
			
		case Affichage:
			
			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);
			
			// Affichage d'une ligne bleue
			couleurCourante(0, 0, 255);
			epaisseurDeTrait(10);
			ligne(0, 0, (largeurFenetre()-600)/2, (hauteurFenetre()-400)/2);

			// Affichage d'un rectangle "saumon"
			couleurCourante(255, 128, 128);
			rectangle((largeurFenetre()-600)/2, (hauteurFenetre()-400)/2, (largeurFenetre()-600)/2+600, (hauteurFenetre()-400)/2+400);

			// Affichage d'un texte vert sombre avec ombrage en police de taille 20
			// L'effet d'ombrage vient tout simplement du dessin du texte en gris clair
			// sous le texte voulu, avec un léger décalage
			couleurCourante(210, 210, 210);
			epaisseurDeTrait(3);
			afficheChaine("L'algo c'est rigolo", 20, 77, 13);
			couleurCourante(0, 128, 0);
			epaisseurDeTrait(2);
			afficheChaine("L'algo c'est rigolo", 20, 75, 15);

			// Affichage d'une image
			if (image != NULL) // Si l'image a pu etre lue
			{
				// On affiche l'image
				ecrisImage((largeurFenetre()-image->largeurImage)/2, (hauteurFenetre()-image->hauteurImage)/2, image->largeurImage, image->hauteurImage, image->donneesRGB);
			}

			// Affichage d'une balle rouge
			couleurCourante(255, 0, 0);
			cercle(xBalle, yBalle, 10);
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
					xBalle = abscisseSouris();
					yBalle = ordonneeSouris();
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
			if (xBalle >= largeurFenetre())
				xBalle = largeurFenetre()-1;
			if (yBalle >= hauteurFenetre())
				yBalle = hauteurFenetre()-1;
			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}