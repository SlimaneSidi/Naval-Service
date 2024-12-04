#include "../include/ourdrawings.h"
#include "../include/visuals.h"



void Draw1()
{		
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran
	
	image = lisBMPRGB("data/img/sky2.bmp");
	demandeTemporisation(20);

	if (image != NULL) // Si l'image a pu etre lue
		{
			// On affiche l'image
			ecrisImage((largeurFenetre() - image->largeurImage) / 2, (hauteurFenetre() - image->hauteurImage) / 2, image->largeurImage, image->hauteurImage, image->donneesRGB);
		}

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



void Draw3() {
    // Clear the window with a blue background
    effaceFenetre(0, 0, 255);

    // Set the color to gray for the docks
    couleurCourante(169, 169, 169);

    // Draw the four docks at the top
    int dockWidth = 100;
    int dockHeight = 200;
    int totalDockWidth = 4 * dockWidth;
    int availableWidth = largeurFenetre() - totalDockWidth;
    int spacing = availableWidth / 5; // 5 spaces: 1 on each side and 3 between docks
    int startX = spacing;
    int startY = 0;

    for (int i = 0; i < 4; ++i) {
        int dockX = startX + i * (dockWidth + spacing);
        int dockY = startY;
        rectangle(dockX, dockY, dockX + dockWidth, dockY + dockHeight);

        // Draw small squares with numbers inside each dock in a vertical line
        int squareSize = 20;
        int squareSpacing = 15;//espacement des quais du bas
        int numSquares = 4 - i; // Decrease the number of squares for each dock
        for (int j = 0; j < numSquares; ++j) {
             int squareX = dockX + squareSpacing;
            int squareY = dockY + squareSpacing + j * (squareSize + squareSpacing);
            couleurCourante(13, 196, 0); // Set color to red for squares
            rectangle(squareX, squareY, squareX + squareSize, squareY + squareSize);
            char number[2];
            sprintf(number, "%d", j + 1);
            couleurCourante(0, 0, 0); // Set color to black for text
            afficheChaine(number, 12, squareX + 5, squareY + 5);
            couleurCourante(169, 169, 169); // Reset color to gray for next square
        }
    }

    // Draw the waiting dock at the bottom
    int waitingDockWidth = 500; // length
    int waitingDockHeight = 80; // Fixed height
    int waitingDockX = largeurFenetre() - waitingDockWidth - 0; // Position it to the right side
    int waitingDockY = hauteurFenetre() - waitingDockHeight - 50;

    rectangle(waitingDockX, waitingDockY, waitingDockX + waitingDockWidth, waitingDockY + waitingDockHeight);

    // Draw four small squares with numbers inside the waiting dock in a line
    int squareSize = 20;
    int squareSpacing = 50; //+haut ou +bas
    for (int j = 0; j < 4; ++j) {
        int squareX = waitingDockX + squareSpacing + j * (squareSize + squareSpacing);
        int squareY = waitingDockY + squareSpacing;
        couleurCourante(255, 0, 0); // Set color to red for squares
        rectangle(squareX, squareY, squareX + squareSize, squareY + squareSize);
        char number[2];
        sprintf(number, "%d", j + 1);
        couleurCourante(0, 0, 0); // Set color to black for text
        afficheChaine(number, 12, squareX + 5, squareY + 5);
        couleurCourante(169, 169, 169); // Reset color to gray for next square
    }

    // Refresh the window to display the drawing
    rafraichisFenetre();
}
