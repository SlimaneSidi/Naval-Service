#include "../include/nomBateaux.h"
#include "../include/moteur.h"

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
    "L'Écume d'Argent",
};

char* choisirNomAleatoire(const char* nomsBateaux[], int taille) {
    if (taille <= 0) return NULL; 
    int index = rand() % taille; 
    char* nom = malloc(strlen(nomsBateaux[index]) + 1); 
    if (nom == NULL) return NULL; 
    strcpy(nom, nomsBateaux[index]); 
    return nom;
}