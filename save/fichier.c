#include "../include/moteur.h"
#include "../include/save.h"

int fichier(void){

	FILE* fichier = NULL; 
	
	fichier = fopen("NavalService.bin", "wb"); 
	
	if(fichier != NULL){
		rewind(fichier); 
		fclose(fichier); 
	
	}
	return 0;
	
}