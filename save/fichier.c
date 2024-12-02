#include <stdio.h>
#include<stdio.h>
#include "../include/moteur.h"
#include "../include/save.h"

int main(void){

	FILE* fichier = NULL; 
	
	fichier = fopen("NavalService.bin", "wb"); 
	
	if(fichier != NULL){
		rewind(fichier); 
		fclose(fichier); 
	
	}
	return 0;
	
}
