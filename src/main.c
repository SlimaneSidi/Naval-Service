#include <stdio.h>
#include <stdlib.h>
#include "../include/moteur.h"
#include "../include/menu.h"
#include "../include/save.h"

int main(void)
{   
    Navire* navireList = NULL;   
    Port* port = malloc(sizeof(Port));
    port = initQuai();
    menu(port, navireList);
    return 0;
}