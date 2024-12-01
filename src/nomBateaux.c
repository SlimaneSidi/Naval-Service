#include "../include/nomBateaux.h"
#include "../include/moteur.h"

/*char* choisirNomAleatoire(const char* nomsBateaux[], int taille) {
    if (taille <= 0) return NULL; 
    char nom[50];
    int index = rand() % taille; 
    nom = nomsBateaux[index];
    printf("%s", nom);
    return nom;
}*/

// Liste de 40 noms de bateaux
const char* nomsBateaux[40] = {
    "L'Océanique",
    "Le Venturier",
    "La Sirène des Mers",
    "Le Nautilus",
    "L'Albatros",
    "Le Phare Vagabond",
    "L'Étoile du Nord",
    "Le Capitaine Courageux",
    "La Perle Noire",
    "L'Aventureux",
    "Le Corsaire",
    "La Marée Bleue",
    "L'Horizon Doré",
    "Le Poseidon",
    "L'Atlantide",
    "La Vague Écarlate",
    "Le Trident",
    "Le Navire Fantôme",
    "L'Explorateur",
    "Le Vaisseau Céleste",
    "La Flèche des Mers",
    "Le Torrent",
    "La Méduse",
    "Le Dauphin Agile",
    "L'Émeraude des Océans",
    "Le Béluga",
    "L'Odyssée",
    "La Galère Royale",
    "Le Roi des Vagues",
    "L'Aube Marine",
    "Le Croiseur Saphir",
    "La Caravelle d'Or",
    "Le Marin Courageux",
    "La Légende des Flots",
    "Le Solitaire",
    "L'Ancre Eternelle",
    "Le Vortex",
    "La Lanterne des Mers",
    "Le Cormoran",
    "La Baleine Bleue"
};

char* choisirNomAleatoire(const char* nomsBateaux[], int taille) {
    if (taille <= 0) return NULL; 
    int index = rand() % taille; 
    char* nom = malloc(strlen(nomsBateaux[index]) + 1); // Allouer de la mémoire pour le nom
    if (nom == NULL) return NULL; // Vérifier si l'allocation a réussi
    strcpy(nom, nomsBateaux[index]); // Copier le nom
    printf("Nom du bateau : %s\n", nom);
    return nom;
}