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
    fprintf(fichier, "Navire Nom Quai: %s\n", navire->NomQuai);
    if (navire->NextNavire != NULL) {
        fprintf(fichier, "Navire Next ID: %d\n", navire->NextNavire->id);
        fprintf(fichier, "Navire Next Nom: %s\n", navire->NextNavire->nom);
        fprintf(fichier, "Navire Next Type: %d\n", navire->NextNavire->type);
        fprintf(fichier, "Navire Etat: %s\n", navire->etat);
        fprintf(fichier, "Navire Capacite Chargement: %d\n", navire->CapaciteChargement);
        fprintf(fichier, "Navire Nom Quai: %s\n", navire->NomQuai);
    }
    else {
        fprintf(fichier, "Navire Next: NULL\n");}
    fclose(fichier);
}

// void AfficherSauvegarde(const char *NavalService) {
//     FILE *fichier = fopen(NavalService, "rb");
//     if (fichier == NULL) {
//         printf("Erreur lors de l'ouverture du fichier");
//         return;
//     }
//     fprintf("Contenu du fichier %s:\n", NavalService);
//     fclose(fichier);
// }

void AfficherSauvegarde(const char *NavalService) {
    FILE *fichier = fopen(NavalService, "rb");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return;
    }
    printf("Contenu du fichier %s:\n", NavalService);
    char caractere;
    while ((caractere = fgetc(fichier)) != EOF) {
        putchar(caractere);
    }
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

Navire* ChargerNavalService(const char *nomFichier){
    FILE *fichier = fopen(nomFichier, "rb");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return NULL;
    }
    Navire* navire = malloc(sizeof(Navire));
    if (navire == NULL) {
        printf("Erreur lors de l'allocation de mémoire");
        return NULL;
    }
    fscanf(fichier, "Navire ID: %d\n", &navire->id);
    fscanf(fichier, "Navire Nom: %s\n", navire->nom);
    fscanf(fichier, "Navire Type: %d\n", (int*)&navire->type);
    fscanf(fichier, "Navire Etat: %s\n", navire->etat);
    fscanf(fichier, "Navire Capacite Chargement: %d\n", &navire->CapaciteChargement);
    fscanf(fichier, "Navire Nom Quai: %s\n", navire->NomQuai);
    char next[10];
    fscanf(fichier, "Navire Next: %s\n", next);
    if (strcmp(next, "NULL") != 0) {
        navire->NextNavire = malloc(sizeof(Navire));
        if (navire->NextNavire == NULL) {
            printf("Erreur lors de l'allocation de mémoire");
            return NULL;
        }
        fscanf(fichier, "Navire Next ID: %d\n", &navire->NextNavire->id);
        fscanf(fichier, "Navire Next Nom: %s\n", navire->NextNavire->nom);
        fscanf(fichier, "Navire Next Type: %d\n", (int*)&navire->NextNavire->type);
        fscanf(fichier, "Navire Etat: %s\n", navire->NextNavire->etat);
        fscanf(fichier, "Navire Capacite Chargement: %d\n", &navire->NextNavire->CapaciteChargement);
        fscanf(fichier, "Navire Nom Quai: %s\n", navire->NextNavire->NomQuai);
    }
    else {
        navire->NextNavire = NULL;
    }
    fclose(fichier);
    return navire;
}