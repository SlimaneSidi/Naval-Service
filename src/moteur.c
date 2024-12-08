#include "../include/moteur.h"
#include "../include/nomBateaux.h"

const char* TypeNavireToString(TypeNavire type) {
    switch (type) {
        case NAVIRE_PASSAGERS: return "Navire de passagers";
        case NAVIRE_MARCHANDISES: return "Navire de marchandises";
        case NAVIRE_PETROLIER: return "Pétrolier";
        case NAVIRE_YACHT: return "Yacht";
        default: return "Inconnu"; }
}

Port* initQuai(){
    Port* port = malloc(sizeof(Port));

    port->QuaiPassager = malloc(sizeof(Quai));   // PASSAGER
    strcpy(port->QuaiPassager->nom, "Quai de navires passagers");
    port->QuaiPassager->NumeroQuai = 1; //id
    port->QuaiPassager->Profondeur = 10;
    port->QuaiPassager->Type = NAVIRE_PASSAGERS;
    port->QuaiPassager->NbNaviresAccostes = 4;
    port->QuaiPassager->NextNavire = NULL;

    port->QuaiMarchand = malloc(sizeof(Quai));   // MARCHAND
    strcpy(port->QuaiMarchand->nom, "Quai de navires marchands");
    port->QuaiMarchand->NumeroQuai = 2; //id
    port->QuaiMarchand->Profondeur = 10;
    port->QuaiMarchand->Type = NAVIRE_MARCHANDISES;
    port->QuaiMarchand->NbNaviresAccostes = 3;
    port->QuaiMarchand->NextNavire = NULL;

    port->QuaiPetrolier = malloc(sizeof(Quai));   // PETROLIER
    strcpy(port->QuaiPetrolier->nom, "Quai de pétroliers");
    port->QuaiPetrolier->NumeroQuai = 3; //id
    port->QuaiPetrolier->Profondeur = 10;
    port->QuaiPetrolier->Type = NAVIRE_PETROLIER;
    port->QuaiPetrolier->NbNaviresAccostes = 1;
    port->QuaiPetrolier->NextNavire = NULL;

    port->QuaiYacht = malloc(sizeof(Quai));   // YACHT
    strcpy(port->QuaiYacht->nom, "Quai de yachts");
    port->QuaiYacht->NumeroQuai = 4; //id
    port->QuaiYacht->Profondeur = 10;
    port->QuaiYacht->Type = NAVIRE_YACHT;
    port->QuaiYacht->NbNaviresAccostes = 3;
    port->QuaiYacht->NextNavire = NULL;

    port->QuaiMouillage = malloc(sizeof(Quai));  // MOUILLAGE
    strcpy(port->QuaiMouillage->nom, "Quai de mouillage");
    port->QuaiMouillage->NumeroQuai = 0; //id
    port->QuaiMouillage->Profondeur = 10;
    port->QuaiMouillage->Type = NAVIRE_ALL;
    port->QuaiMouillage->NbNaviresAccostes = 4;
    port->QuaiMouillage->NextNavire = NULL;

    return port;
}

void AjouterFinListeNavire(Navire** navire, Navire* new, Port* port) {
    if (*navire == NULL) {
        *navire = new;
    } else {
        Navire* current = *navire;
        while (current->NextNavire != NULL) {
            current = current->NextNavire;
        }
        current->NextNavire = new;
    }
    new->NextNavire = NULL;
    // Allouer le navire au quai correspondant
    switch (new->type) {
        case NAVIRE_PASSAGERS:
            if (port->QuaiPassager == NULL) {
                port->QuaiPassager = malloc(sizeof(Quai));
                strcpy(port->QuaiPassager->nom, "Quai de navires passagers");
                port->QuaiPassager->NumeroQuai = 1;
                port->QuaiPassager->Profondeur = 10;
                port->QuaiPassager->Type = NAVIRE_PASSAGERS;
            }
            new->NomQuai = port->QuaiPassager->nom;
            break;
        case NAVIRE_MARCHANDISES:
            if (port->QuaiMarchand == NULL) {
                port->QuaiMarchand = malloc(sizeof(Quai));
                strcpy(port->QuaiMarchand->nom, "Quai de navires marchands");
                port->QuaiMarchand->NumeroQuai = 2;
                port->QuaiMarchand->Profondeur = 15;
                port->QuaiMarchand->Type = NAVIRE_MARCHANDISES;
            }
            new->NomQuai = port->QuaiMarchand->nom;
            break;
        case NAVIRE_PETROLIER:
            if (port->QuaiPetrolier == NULL) {
                port->QuaiPetrolier = malloc(sizeof(Quai));
                strcpy(port->QuaiPetrolier->nom, "Quai de pétroliers");
                port->QuaiPetrolier->NumeroQuai = 3;
                port->QuaiPetrolier->Profondeur = 20;
                port->QuaiPetrolier->Type = NAVIRE_PETROLIER;
            }
            new->NomQuai = port->QuaiPetrolier->nom;
            break;
        case NAVIRE_YACHT:
            if (port->QuaiYacht == NULL) {
                port->QuaiYacht = malloc(sizeof(Quai));
                strcpy(port->QuaiYacht->nom, "Quai de yachts");
                port->QuaiYacht->NumeroQuai = 4;
                port->QuaiYacht->Profondeur = 5;
                port->QuaiYacht->Type = NAVIRE_YACHT;
            }
            new->NomQuai = port->QuaiYacht->nom;
            break;
        default:
            printf("Type de navire inconnu\n");
            break;
    }
}
Navire* CreerNavire(Navire* navire) {
    static int id_counter = 1; // ID du navire
    Navire* navire1 = malloc(sizeof(Navire));

    const char* nomAleatoire = choisirNomAleatoire(nomsBateaux, 40);
    navire1->nom = malloc(strlen(nomAleatoire) + 1);
    strcpy(navire1->nom, nomAleatoire);
    printf("Nom du navire : %s\n\n",navire1->nom);
    navire1->id = id_counter++;
    printf("Identifiant du navire : %d\n\n",navire1->id);
    printf("Choisissez le type de navire (NavirePassager (1), NavireMarchand (2), Petrolier (3), ou Yacht (4)) : ");
    int typeTemp;
    scanf("%d", &typeTemp);
    if (typeTemp == 1) {
        navire1->type = NAVIRE_PASSAGERS;
    } else if (typeTemp == 2) {
        navire1->type = NAVIRE_MARCHANDISES;
    } else if (typeTemp == 3) {
        navire1->type = NAVIRE_PETROLIER;
    } else if (typeTemp == 4) {
        navire1->type = NAVIRE_YACHT;
    } else {
        printf("\n\n");
        return NULL;
    }
    printf("\n");
    
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

Navire* CreerNavireAleatoire(Navire* navire) {
    static int id_counter = 1; // ID du navire
    Navire* navire1 = malloc(sizeof(Navire));
    if (navire1 == NULL) {
        printf("Erreur d'allocation de mémoire pour le navire\n");
        exit(1);
    }

    const char* nomAleatoire = choisirNomAleatoire(nomsBateaux, 40);
    navire1->nom = malloc(strlen(nomAleatoire) + 1);
    if (navire1->nom == NULL) {
        printf("Erreur d'allocation de mémoire pour le nom du navire\n");
        free(navire1);
        exit(1);
    }
    strcpy(navire1->nom, nomAleatoire);
    printf("Nom du navire : %s\n\n", navire1->nom);
    navire1->id = id_counter++;
    navire1->type = rand() % 4 + 1;
    strcpy(navire1->etat, "en mer");
    navire1->CapaciteChargement = rand() % 1000 + 1;
    navire1->NextNavire = NULL;

    return navire1;
}

void AfficherQuai(Port* port){
    Port* port1 = port;

    printf("-- %s : \n",port1->QuaiPassager->nom);
    printf("Numéro du quai : %d\n",port1->QuaiPassager->NumeroQuai);   // PASSAGER
    //printf("Taille du quai : %d\n",port1->QuaiPassager->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiPassager->Profondeur);
    printf("Type de navire : %s\n",TypeNavireToString(port1->QuaiPassager->Type)); 
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiPassager->NbNaviresAccostes);

    printf("-- %s : \n",port1->QuaiMarchand->nom);
    printf("Numéro du quai : %d\n",port1->QuaiMarchand->NumeroQuai);   // MARCHAND
    //printf("Taille du quai : %d\n",port1->QuaiMarchand->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiMarchand->Profondeur);
    printf("Type de navire : %s\n",TypeNavireToString(port1->QuaiMarchand->Type)); 
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiMarchand->NbNaviresAccostes);

    printf("-- %s : \n",port1->QuaiPetrolier->nom);
    printf("Numéro du quai : %d\n",port1->QuaiPetrolier->NumeroQuai);   // PETROLIER
    //printf("Taille du quai : %d\n",port1->QuaiPetrolier->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiPetrolier->Profondeur);
    printf("Type de navire : %s\n",TypeNavireToString(port1->QuaiPetrolier->Type)); 
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiPetrolier->NbNaviresAccostes);

    printf("-- %s : \n",port1->QuaiYacht->nom);
    printf("Numéro du quai : %d\n",port1->QuaiYacht->NumeroQuai);   // YACHT
    //printf("Taille du quai : %d\n",port1->QuaiYacht->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiYacht->Profondeur);
    printf("Type de navire : %s\n",TypeNavireToString(port1->QuaiYacht->Type));
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiYacht->NbNaviresAccostes);

    printf("-- %s : \n",port1->QuaiMouillage->nom);
    printf("Numéro du quai : %d\n",port1->QuaiMouillage->NumeroQuai);  // MOUILLAGE
    //printf("Taille du quai : %d\n",port1->QuaiMouillage->QuaiSize);
    printf("Profondeur du quai : %d\n",port1->QuaiMouillage->Profondeur);
    printf("Type de navire : %s\n",TypeNavireToString(port1->QuaiMouillage->Type));
    printf("Nombre maximum de navires accostés : %d\n\n",port1->QuaiMouillage->NbNaviresAccostes);
}

void AfficherNavire(Navire* navire){
    if (navire == NULL) {printf("Aucun navire n'a été créé\n"); return;}
    Navire* navire1 = navire;
    while (navire1 != NULL) {
        printf("Nom du navire : %s\n",navire1->nom);
        printf("Identifiant du navire : %d\n",navire1->id);
        printf("Type de navire : %s\n",TypeNavireToString(navire1->type));
        printf("Etat du navire : %s\n",navire1->etat);
        printf("Capacité de chargement du navire : %d\n",navire1->CapaciteChargement);
        printf("Assigné au quai : %s\n", navire1->NomQuai);
        printf("\n");
        navire1 = navire1->NextNavire;
    }
}

int boutonClicked(int OnClicked){
    OnClicked = 1;
    return OnClicked;
}

Navire* genererBateaux(Port* port, Navire** navire, int OnClicked) {
    printf("(1) - Génération d'un navire aléatoire\n");
    printf("(2) - Génération d'un navire manuelle\n");
    int choix = 0;
    scanf("%d", &choix);
    if (choix == 1) {
        Navire* newNavire = CreerNavireAleatoire(NULL);
        AjouterFinListeNavire(navire, newNavire, port);
        if (*navire == NULL) {
            *navire = newNavire;}
        OnClicked = 0;
        AfficherNavire(*navire);
        return *navire;}
    else if (choix == 2) {
        Navire* newNavire = CreerNavire(NULL);
        AjouterFinListeNavire(navire, newNavire, port);
        if (*navire == NULL) {
            *navire = newNavire;}
        OnClicked = 0;
        AfficherNavire(*navire);
        return *navire;}
    else {printf("Choix invalide\n");
        return *navire;}
}

void gestionMouillage(Navire* navire, Port* port){
    strcpy(navire->etat, "en attente");
    distribNavires(navire, port);
}


//PremierElementListe correspond à &(port->QuaiMouillage->NextNavire)
int supprimeNavire(Navire**PremierElementListe,Navire* navireASupprimer){
    //printf("Tous les quais sont pleins. Le navire sera supprimé.\n");
    if (PremierElementListe == NULL || *PremierElementListe == NULL || navireASupprimer == NULL) {
        printf("Erreur de suppression\n");
        return 0;}
    // Si le navire à supprimer est le premier élément ( peu probable dans la logique des choses)
    if (*PremierElementListe == navireASupprimer) {
        *PremierElementListe = navireASupprimer->NextNavire; // Déplace le PremierElementListe au suivant
        free(navireASupprimer);              // Libère la mémoire du navire
        printf("Navire supprimé (premier de la liste).\n");
        return 0;}
    // Recherche du navire précédant celui à supprimer
    Navire* tmp = *PremierElementListe;
    while (tmp->NextNavire != NULL && tmp->NextNavire != navireASupprimer) {
        tmp = tmp->NextNavire;}
    // Si le navire est trouvé, on le retire de la liste
    if (tmp->NextNavire == navireASupprimer) {
        tmp->NextNavire = navireASupprimer->NextNavire; // Sauter le navire
        free(navireASupprimer);                            // Libérer la mémoire
        printf("Navire supprimé de la liste.\n");} 
    else {
        printf("Erreur : Navire à supprimer introuvable dans la liste.\n");}
    return 0;
}

Quai* distribNavires(Navire *navire, Port*port){
    if(navire->type == NAVIRE_PASSAGERS){
        if(port->QuaiYacht->NbNaviresAccostes < 4){
            port->QuaiPassager->NbNaviresAccostes++; 
            strcpy(navire->etat, "accosté");
            printf("navire de passagers ajoute au quai des passagers ");
            return port->QuaiPassager;}
        else if (port->QuaiMouillage->NbNaviresAccostes < 4){
            port->QuaiMouillage->NbNaviresAccostes ++;
            strcpy(navire->etat, "accosté");
            printf("bateau au quai de mouillage");
            return port->QuaiMouillage;}
        else { supprimeNavire(&(port->QuaiMouillage->NextNavire),navire); 
        printf("navire supprime");
        return NULL;}}

    else if (navire->type == NAVIRE_MARCHANDISES){
        if(port->QuaiMarchand->NbNaviresAccostes < 3){
            port->QuaiMarchand->NbNaviresAccostes ++; 
            strcpy(navire->etat, "accosté");
            return port->QuaiMarchand;}
        else if (port->QuaiMouillage->NbNaviresAccostes < 4){
            port->QuaiMouillage->NbNaviresAccostes ++; 
            return port->QuaiMouillage;} 
        else { supprimeNavire(&(port->QuaiMouillage->NextNavire),navire); 
        printf("navire supprime");
        return NULL;}}

    else if (navire->type == NAVIRE_PETROLIER ){
        if( port->QuaiPetrolier->NbNaviresAccostes < 1){
            port->QuaiPetrolier->NbNaviresAccostes ++; 
            strcpy(navire->etat, "accosté");
            return port->QuaiPetrolier;}
        else if (port->QuaiMouillage->NbNaviresAccostes < 4){
            port->QuaiMouillage->NbNaviresAccostes ++; 
            return port->QuaiMouillage;}
        else {supprimeNavire(&(port->QuaiMouillage->NextNavire),navire)  ; 
        printf("navire supprime");
        return NULL;}}

    else if (navire->type == NAVIRE_YACHT ){
        if( port->QuaiYacht->NbNaviresAccostes < 4) {
            port->QuaiYacht->NbNaviresAccostes ++; 
            strcpy(navire->etat, "accosté");
            return port->QuaiYacht;} 
        else if (port->QuaiMouillage->NbNaviresAccostes < 4){
            port->QuaiMouillage->NbNaviresAccostes ++; 
            return port->QuaiMouillage;}
        else {supprimeNavire(&(port->QuaiMouillage->NextNavire),navire); //Quel est le premier element ?
        printf("navire supprime");
        return NULL;}}
    return NULL;
}

