#include <stdio.h>
#include <stdlib.h>
#include "../include/moteur.h"
#include "../include/menu.h"

int main(void)
{   
    Navire* navire = NULL;   
    Port* port = malloc(sizeof(Port));
    port = initQuai();
    menu(port, navire);
    return 0;
}