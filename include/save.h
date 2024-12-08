#ifndef SAVE_H
#define SAVE_H

#include "moteur.h"

void saveNavalService(Navire* navire, const char *nomFichier);
void AfficherSauvegarde(const char *NavalService);
int CreationFichier();
Navire* ChargerNavalService(const char *nomFichier);
//, const char *quai, const char *navire
#endif

