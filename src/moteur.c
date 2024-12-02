#include "../include/moteur.h"

Quai* CreerQuai(Quai* quai){
    Quai* quai1 = malloc(sizeof(Quai));

    printf("type de quai : petroliernuméro du quai : 1");
    
    printf("\n");
    
    printf("taille du quai : ");
    printf("\n");
    
    printf("Choisissez la profondeur du quai : ");
    scanf("%d", &quai1->Profondeur);
    printf("\n");
    
    printf("Choisissez le type de navire (NavirePassager, NavireMarchand, Petrolier, ou Yacht) : ");
    char typeTemp[SIZE];
    scanf("%s", typeTemp);
    printf("\n");

    if (strcmp(typeTemp, "NavirePassager") == 0) {
        quai1->Type[0] = &(TYPE_NAVIRE) { .NavirePassagers = "NavirePassager" };
    } else if (strcmp(typeTemp, "NavireMarchand") == 0) {
        quai1->Type[0] = &(TYPE_NAVIRE) { .NavireMarchand = "NavireMarchand" };
    } else if (strcmp(typeTemp, "Petrolier") == 0) {
        quai1->Type[0] = &(TYPE_NAVIRE) { .Petrolier = "Petrolier" };
    } else if (strcmp(typeTemp, "Yacht") == 0) {
        quai1->Type[0] = &(TYPE_NAVIRE) { .Yacht = "Yacht" };
    } else {
        printf("Type de navire invalide.\n");
        CreerQuai(quai);
    }
    printf("Choisissez le nombre maximum de navires accostés : ");
    scanf("%d", &quai1->MaxNaviresAccostés);
    printf("\n");

    quai1->NextNavire = NULL;
    printf("Quai : %d\n", quai1->NumeroQuai);
    return quai1;
}

Navire* CreerNavire(Navire* navire){
    Navire* navire1 = malloc(sizeof(Navire));                                                                                                                                                                                                                                                                                                                                                                   
    //if (navire1 == NULL) {return NULL;}

    printf("Choisissez l'identifiant du navire : ");
    scanf("%d", &navire1->id);
    printf("\n");

    printf("Choisissez le type de navire (NavirePassager, NavireMarchand, Petrolier, ou Yacht) : ");
    char typeTemp[SIZE];
    scanf("%s", typeTemp);
    printf("\n");

    if (strcmp(typeTemp, "NavirePassager") == 0) {
        navire1->type[0] = &(TYPE_NAVIRE) { .NavirePassagers = "NavirePassager" };
    } else if (strcmp(typeTemp, "NavireMarchand") == 0) {
        navire1->type[0] = &(TYPE_NAVIRE) { .NavireMarchand = "NavireMarchand" };
    } else if (strcmp(typeTemp, "Petrolier") == 0) {
        navire1->type[0] = &(TYPE_NAVIRE) { .Petrolier = "Petrolier" };
    } else if (strcmp(typeTemp, "Yacht") == 0) {
        navire1->type[0] = &(TYPE_NAVIRE) { .Yacht = "Yacht" };
    } else {
        printf("Type de navire invalide.\n");
        CreerNavire(navire); // Si le type de navire n'est pas valide, on recommence la création du navire (probleme pour la demande suivante faite 2 fois)
    }
    printf("Choisissez l'état du navire (en mer (1), accosté (2), en attente (3)) : ");
    int etatTemp;
    scanf("%d", &etatTemp);
    if (etatTemp == 1) {
        strcpy(navire1->etat, "en mer");
    } else if (etatTemp == 2) {
        strcpy(navire1->etat, "accosté");
    } else if (etatTemp == 3) {
        strcpy(navire1->etat, "en attente");
    } else {
        printf("\n\n");
        return NULL;
    }
    printf("\n");
    printf("Choisissez la capacité de chargement du navire : ");
    scanf("%d", &navire1->CapaciteChargement);
    printf("\n");

    return navire1;
}

void AfficherQuai(Quai* quai){
    Quai* quai1 = quai;
    while (quai1 != NULL) {
        printf("Numéro du quai : %d\n",quai1->NumeroQuai);
        printf("Taille du quai : %d\n",quai1->QuaiSize);
        printf("Profondeur du quai : %d\n",quai1->Profondeur);
        printf("Type de navire : %s\n",quai1->Type); // NE FONCTIONNE PAS
        printf("Nombre maximum de navires accostés : %d\n",quai1->MaxNaviresAccostés);
        quai1 = quai1->NextNavire;
    }
}

void AfficherNavire(Navire* navire){
    Navire* navire1 = navire;
    //while (navire1 != NULL) {
    printf("Identifiant du navire : %d\n",navire1->id);
    printf("Type de navire : %s\n",navire1->type); // NE FONCTIONNE PAS
    printf("Etat du navire : %s\n",navire1->etat);
    printf("Capacité de chargement du navire : %d\n",navire1->CapaciteChargement);
    //}
}

void AjouterFinListeQuai(Quai* quai, Quai* new) {
    if (quai == NULL) {quai = new; return;}
    Quai* current = quai;
    while (current->NextNavire != NULL) {current = current->NextNavire;}
    current->NextNavire = new;
    new->NextNavire = NULL;
}

void AjouterFinListeNavire(Navire* navire, Navire* new) {
    if (navire == NULL) {navire = new; return;}
    Navire* current = navire;
    while (current->NextNavire != NULL) {current = current->NextNavire;}
    current->NextNavire = new;
    new->NextNavire = NULL;
}
//mouillage 0 , passager 1 , marchand 2, yacht 4, petrolier 3
Quai* distibNavires(Navires *navire, Port*port){
   if(  navire->type ==NavirePassagers &&  QuaiPassagers->MaxNaviresAccostés < 4){
    QuaiPassagers->MaxNaviresAccostés ++; 
    navire->NumeroQuai = 1 ;
    return QuaiPassagers;
    printf("navire passagers +1");
   }else if (mouillage->MaxNaviresAccostés < 4){
    mouillage->MaxNaviresAccostés ++;
    strcpy(navire->etat, "accosté");
   
    navire->NumeroQuai = 0 ; 
     return mouillage ; 
    printf("bateau au quai de mouillage");
   }else { supprime (navire) ; 
   printf("navire supprime");
   return ; }

if(  navire->type == NavireMarchand &&  QuaiMarchand->MaxNaviresAccostés < 4){
    QuaiMarchand->MaxNaviresAccostés ++; 
    navire->NumeroQuai = 2 ;
    strcpy(navire->etat, "accosté");
    return QuaiMarchand ; 
   }else if (mouillage->MaxNaviresAccostés < 4){
    mouillage->MaxNaviresAccostés ++; 
    navire->NumeroQuai = 0 ;
     return mouillage ; 
   }else { supprime (navire) ; 
   printf("navire supprime");
   return ;}

   if(  navire->type ==Petrolier &&  QuaiPetrolier->MaxNaviresAccostés < 4){
    QuaiPetrolier->MaxNaviresAccostés ++; 
    navire->NumeroQuai = 3 ;
    strcpy(navire->etat, "accosté");
    return QuaiPetrolier;

   }else if (mouillage->MaxNaviresAccostés < 4){
    mouillage->MaxNaviresAccostés ++; 
    navire->NumeroQuai = 0 ;
     return mouillage ; 
   }else { supprime (navire) ; 
   printf("navire supprime");
   return ;}
if(  navire->type ==Yacht &&  QuaiYacht->MaxNaviresAccostés < 4){
    QuaiYacht->MaxNaviresAccostés ++; 
    navire->NumeroQuai = 4 ;
     strcpy(navire->etat, "accosté");
    return QuaiYacht ; 
   }else if (mouillage->MaxNaviresAccostés < 4){
    mouillage->MaxNaviresAccostés ++; 
    navire->NumeroQuai = 0 ;
    return mouillage ; 
   }else { supprime (navire) ; 
   printf("navire supprime");
   return ;}
}

void gestionMouillage ( Navires* navire, int etatBouton){
    strcpy(navire1->etat, "en attente");
    NumeroQuai = 0;
    if (etatBouton ==1) { 
        printf("Bouton presse");
        printf("navires en zone de mouillage vont aux quais si y a de la place ");
    distibNavires(navire, Quai*quai);
    }

return ; 
}

int etatBouton ( ){
    printf("clic de la souris sur le bouton ");
    //return 1 ; 
    //else return 0 ;  
    //pour tester le programme :
    retrun 1 ; 
}


// plutot que de demander à l'utilisateur l'état du bateau , on le fait aleatoiremement
/*srand(time(NULL));
int case = rand()%4+1;
switch (case){
    case 1 : strcpy(navire1->etat, "en mer");
    break; 
    case 2 : strcpy(navire1->etat, "accosté");
    distibNavires(navires1) ; 
 
    break ; 
    case 3 : strcpy(navire1->etat, "en attente");
    NumeroQuai = 0;
    break ; 
default:
            printf("Erreur : case non définie\n");
            break;
    }
} */
//faire un timeur pour enerer des bateaux au bout d'un certain temps et les envoyer en moiuillage
// nom fonction : delay avec srand et differents temps aleatoires 
// fonction gestion mouillage retourne un etat pour lequel distrib se fait
void delay () {
    srand(time(NULL));

    // 3 differents temps d'attente en secondes
    int delais[] = {5, 10, 30};
    int taille = sizeof(delais) / sizeof(delais[0]);
    //la division de la taille totale du tableau par la taille d'un élément => le nombre total d'éléments dans le tableau

    for (int i = 0; i < 140; i++) { 

        int cas = rand() % taille;
        int temps_attente = delais[cas];

        printf("Nouveau bateau dans %d secondes... \n", temps_attente);
        while( temps_attente != 0 ){
       temps_attente -- ; 
        }

        printf("bateau genere");//on va devoir generer le bateau => appel de la fonction
        gestionMouillage ( Navires* navires)
    } char reponse = '/0'
    printf("souhaitez-vous continuer à generer des bateaux ? O/N");
    scanf("%s", reponse);
    if (reponse == 'O'){
        void delay() ; } 
    }
}
