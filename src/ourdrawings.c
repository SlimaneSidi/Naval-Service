#include "../include/ourdrawings.h"
#include "../include/visuals.h"



void Draw1()
{		
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran
	
	image = lisBMPRGB("data/img/ISEN.bmp");
	demandeTemporisation(20);


	effaceFenetre(255, 255, 255);
	couleurCourante(255, 128, 128);
	rectangle((largeurFenetre() - 600) / 2, (hauteurFenetre() - 400) / 2, (largeurFenetre() - 600) / 2 + 600, (hauteurFenetre() - 400) / 2 + 400);

	////////////////////////BATEAU///////

	couleurCourante(0, 0, 255);

	// Draw the hull of the boat
	triangle(200, 200, 600, 200, 300, 100);
	triangle(600, 200, 500, 100, 300, 100);

	// Set the color to white for the sail
	couleurCourante(255, 255, 255);

	// Draw the sail of the boat
	triangle(400, 200, 400, 400, 500, 200);

	rafraichisFenetre();

	/////////////////////////////////////

	// Affichage d'une image
	if (image != NULL) // Si l'image a pu etre lue
	{
		// On affiche l'image
		ecrisImage((largeurFenetre() - image->largeurImage) / 2, (hauteurFenetre() - image->hauteurImage) / 2, image->largeurImage, image->hauteurImage, image->donneesRGB);
	}
}

void Draw2(){ 
    
    effaceFenetre(255, 255, 255);
    couleurCourante(255, 128, 128);
    rectangle((largeurFenetre() - 600) / 2, (hauteurFenetre() - 400) / 2, (largeurFenetre() - 600) / 2 + 600, (hauteurFenetre() - 400) / 2 + 400);

    ////////////////////////BATEAU///////

    couleurCourante(0, 0, 255);

    // Draw the hull of the boat
    triangle(200, 200, 600, 200, 300, 100);
    triangle(600, 200, 500, 100, 300, 100);

    // Set the color to white for the sail
    couleurCourante(255, 255, 255);

    // Draw the sail of the boat
    triangle(400, 200, 400, 400, 500, 200);

    rafraichisFenetre();

    /////////////////////////////////////
}