#include "../include/moteur.h"
#include "../include/save.h"

void saveNavalService(Navire* navire, const char* filename) {
    if (navire == NULL) {
        printf("Il n'y a aucun navires à sauvegarder.\n");
        return;
    }
    FILE* fichier = fopen(filename, "wb");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    fprintf(fichier, "Navire ID: %d\n", navire->id);
    fprintf(fichier, "Navire Nom: %s\n", navire->nom);
    fprintf(fichier, "Navire Type: %d\n", navire->type);
    fprintf(fichier, "Navire Etat: %s\n", navire->etat);
    fprintf(fichier, "Navire Capacite Chargement: %d\n", navire->CapaciteChargement);
    if (navire->NextNavire != NULL) {
        fprintf(fichier, "Navire Next ID: %d\n", navire->NextNavire->id);
        fprintf(fichier, "Navire Next Nom: %s\n", navire->NextNavire->nom);
        fprintf(fichier, "Navire Next Type: %d\n", navire->NextNavire->type);
        fprintf(fichier, "Navire Etat: %s\n", navire->etat);
        fprintf(fichier, "Navire Capacite Chargement: %d\n", navire->CapaciteChargement);
    }

    else {
        fprintf(fichier, "Navire Next: NULL\n");}
    fclose(fichier);
}

void AfficherSauvegarde(const char *NavalService) {
    FILE *fichier = fopen(NavalService, "rb");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return;
    }
    //fprintf(NavalService, "Contenu du fichier %s:\n");
    fclose(fichier);
}

int CreationFichier(){
	FILE* fichier = NULL; 
	fichier = fopen("NavalService.bin", "wb"); 
	if(fichier != NULL){
		rewind(fichier); 
		fclose(fichier); }
	return 0;
}
