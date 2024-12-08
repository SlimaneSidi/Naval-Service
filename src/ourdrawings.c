#include "../include/ourdrawings.h"
#include <stdio.h>
#include <stdlib.h>

Square docks[4][4];
Square waitingDock[4];

void initializeSquares() {
    int dockWidth = 100;
    int totalDockWidth = 4 * dockWidth;
    int availableWidth = largeurFenetre() - totalDockWidth;
    int spacing = availableWidth / 5; // 5 spaces: 1 on each side and 3 between docks
    int startX = spacing;
    int startY = 0;
    int squareSize = 20;
    int squareSpacing = 10;

    for (int i = 0; i < 4; ++i) {
        int dockX = startX + i * (dockWidth + spacing);
        int dockY = startY;
        int numSquares = 4 - i; // Decrease the number of squares for each dock
        for (int j = 0; j < numSquares; ++j) {
            docks[i][j].x = dockX + squareSpacing;
            docks[i][j].y = dockY + squareSpacing + j * (squareSize + squareSpacing);
            docks[i][j].size = squareSize;
            docks[i][j].r = 255;
            docks[i][j].g = 0;
            docks[i][j].b = 0;
            sprintf(docks[i][j].number, "%d", j + 1);
        }
    }

    int waitingDockWidth = 500; // length
    int waitingDockHeight = 80; // Fixed height
    int waitingDockX = largeurFenetre() - waitingDockWidth; // Position it to the right side
    int waitingDockY = hauteurFenetre() - waitingDockHeight - 50;

    for (int j = 0; j < 4; ++j) {
        waitingDock[j].x = waitingDockX + squareSpacing + j * (squareSize + squareSpacing);
        waitingDock[j].y = waitingDockY + squareSpacing;
        waitingDock[j].size = squareSize;
        waitingDock[j].r = 255;
        waitingDock[j].g = 0;
        waitingDock[j].b = 0;
        sprintf(waitingDock[j].number, "%d", j + 1);
    }
}

void changeSquareColor(int dockIndex, int squareIndex, int r, int g, int b) {
    if (dockIndex < 4) {
        docks[dockIndex][squareIndex].r = r;
        docks[dockIndex][squareIndex].g = g;
        docks[dockIndex][squareIndex].b = b;
    } else {
        waitingDock[squareIndex].r = r;
        waitingDock[squareIndex].g = g;
        waitingDock[squareIndex].b = b;
    }
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
        for (int j = 0; j < 4 - i; ++j) {
            couleurCourante(docks[i][j].r, docks[i][j].g, docks[i][j].b); // Set color for squares
            rectangle(docks[i][j].x, docks[i][j].y, docks[i][j].x + docks[i][j].size, docks[i][j].y + docks[i][j].size);
            couleurCourante(0, 0, 0); // Set color to black for text
            afficheChaine(docks[i][j].number, 12, docks[i][j].x + 5, docks[i][j].y + 5);
            couleurCourante(169, 169, 169); // Reset color to gray for next square
        }
    }

    // Draw the waiting dock at the bottom
    int waitingDockWidth = 500; // length
    int waitingDockHeight = 80; // Fixed height
    int waitingDockX = largeurFenetre() - waitingDockWidth; // Position it to the right side
    int waitingDockY = hauteurFenetre() - waitingDockHeight - 50;

    rectangle(waitingDockX, waitingDockY, waitingDockX + waitingDockWidth, waitingDockY + waitingDockHeight);

    // Draw four small squares with numbers inside the waiting dock in a line
    for (int j = 0; j < 4; ++j) {
        couleurCourante(waitingDock[j].r, waitingDock[j].g, waitingDock[j].b); // Set color for squares
        rectangle(waitingDock[j].x, waitingDock[j].y, waitingDock[j].x + waitingDock[j].size, waitingDock[j].y + waitingDock[j].size);
        couleurCourante(0, 0, 0); // Set color to black for text
        afficheChaine(waitingDock[j].number, 12, waitingDock[j].x + 5, waitingDock[j].y + 5);
        couleurCourante(169, 169, 169); // Reset color to gray for next square
    }

     Button* bouton3 = initializeButton(25, 500, "Afficher quai");
    Button* bouton4 = initializeButton(25, 440, "Button 4");
    Button* bouton5 = initializeButton(25, 380, "Button 5");
    drawButton(bouton3);
    drawButton(bouton4);
    drawButton(bouton5);

    // Refresh the window to display the drawing
    rafraichisFenetre();
}

void Draw2() {
    effaceFenetre(255, 255, 255);
    couleurCourante(255, 128, 128);
    rectangle((largeurFenetre() - 600) / 2, (hauteurFenetre() - 400) / 2, (largeurFenetre() - 600) / 2 + 600, (hauteurFenetre() - 400) / 2 + 400);

    // Draw the boat
    couleurCourante(0, 0, 255);

    // Draw the hull of the boat
    triangle(200, 200, 600, 200, 300, 100);
    triangle(600, 200, 500, 100, 300, 100);

    // Set the color to white for the sail
    couleurCourante(255, 255, 255);

    // Draw the sail of the boat
    triangle(400, 200, 400, 400, 500, 200);

    rafraichisFenetre();
}

void Draw1() {
    static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran
    
    image = lisBMPRGB("data/img/sky2.bmp");
    demandeTemporisation(20);

    if (image != NULL) { // Si l'image a pu etre lue
        // On affiche l'image
        ecrisImage((largeurFenetre() - image->largeurImage) / 2, (hauteurFenetre() - image->hauteurImage) / 2, image->largeurImage, image->hauteurImage, image->donneesRGB);
    }

    // Draw the boat
    couleurCourante(0, 0, 255);

    // Draw the hull of the boat
    triangle(200, 200, 600, 200, 300, 100);
    triangle(600, 200, 500, 100, 300, 100);

    // Set the color to white for the sail
    couleurCourante(255, 255, 255);

    // Draw the sail of the boat
    triangle(400, 200, 400, 400, 500, 200);

    // Draw the first button
    Button* myButton1 = initializeButton(50, 100, "Jouer");
    drawButton(myButton1);

    // Draw the second button to the right of the first button
    Button* myButton2 = initializeButton(650, 100, "Quitter");
    drawButton(myButton2);

    rafraichisFenetre();
}