#ifndef SAVE_H
#define SAVE_H

#include "moteur.h"

void fichier(void);
int saveNavalService(Quai* quai,Navire* navire, char NavalService);
void AfficherSauvegarde(const char *NavalService, const char *quai,const char *navire);

#endif

