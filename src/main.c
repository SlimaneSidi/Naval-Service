#include <stdio.h>
#include <stdlib.h>
#include "../include/moteur.h"
#include "../include/menu.h"

int main(void)
{
    Navire* navire = NULL;
    Quai* quai = malloc(sizeof(Quai));   
    
    menu(quai, navire);
    return 0;
}