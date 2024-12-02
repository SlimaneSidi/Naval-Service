#include "../include/moteur.h"
#include "../include/save.h"

int saveNavalService(Quai* quai,Navire* navire, char NavalService)
{
    FILE* fichier = fopen(NavalService, "wb");
    if (fichier == NULL)
    {   printf("Erreur lors de l'ouverture du fichier");
        return 0;
    }

    Quai* current_quai = quai;
    while (current_quai != NULL)
    {
        fprintf(fichier, "Quai \n", current_quai->quai);
        current_quai= current_quai->suiv;
    }
    Navire* current_navire = navire;
    while (current_navire != NULL)
    {
        fprintf(fichier, "Navire\n", current_navire->navire);
        current_navire = current_navire->suiv;
    }

    fclose(fichier);
    return 1;
}

/*void AfficherSauvegarde(const char *NavalService){
    FILE * fichier = fopen(NavalService, "rb");
    if (fichier == NULL)
    {   printf("Erreur lors de l'ouverture du fichier");
        return 0;
    }
    fprintf("Contenu du fichier %s:\n", NavalService);
    char caractere;
    while ((charactere = fgetc(fichier)) != EOF){
        putchar(caractere);
    }
    fclose(fichier);   
}   */

void AfficherSauvegarde(const char *NavalService){
   fichier *NavalService = navire;
    AfficherNavire(Navire* navire){
    printf("Identifiant du navire : %d\n",navire1->id);
    printf("Type de navire : %s\n",navire1->type);
    }
    AfficherQuai(Quai* quai){
        printf("Numéro du quai : %d\n",quai1->NumeroQuai);
   
    }
}



int main(void){
    AfficherSauvegarde("sauvegarde.bin");
    return 0;
}


