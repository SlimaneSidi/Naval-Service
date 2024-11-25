#include "../include/visuals.h"


void drawBoat() {
    // Initialize the graphics window
    gfx_open(800, 600, "Boat Shape");

    // Set the color to blue for the boat
    gfx_color(0, 0, 255);

    // Draw the hull of the boat
    gfx_line(200, 400, 600, 400);
    gfx_line(200, 400, 300, 500);
    gfx_line(600, 400, 500, 500);
    gfx_line(300, 500, 500, 500);

    // Set the color to white for the sail
    gfx_color(255, 255, 255);

    // Draw the sail of the boat
    gfx_line(400, 400, 400, 200);
    gfx_line(400, 200, 500, 400);

    // Wait for the user to press a key before closing
    gfx_wait();
}

