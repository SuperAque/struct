#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structures de données
typedef struct Livre {
    int id;
    char titre[50];
    char auteur[50];
    bool disponible;
    struct Livre* suivant;
} Livre;

typedef struct Etudiant {
    int apogee;
    char nom[50];
    char prenom[50];
    struct Etudiant* suivant;
} Etudiant;

typedef struct Emprunt {
    int idL;        // id de Livre
    int apogeE;     // Apogee de l'etudiant
    char dateEm[50];// date d'emprunt
    char dateRe[50];// date de retour
    struct Emprunt* suivant;
} Emprunt;

typedef struct Pile {
    Emprunt* sommet;
} Pile;

typedef struct File {
    Emprunt* tete;
    Emprunt* queue;
} File;

typedef struct Noeud {
    Livre livre;
    struct Noeud* gauche;
    struct Noeud* droite;
} Noeud;

void ajouterLivre(Livre** liste, int id, const char* titre, const char* auteur, bool disponible) {
    Livre* nouveauLivre = (Livre*)malloc(sizeof(Livre));
    nouveauLivre->id = id;
    strcpy(nouveauLivre->titre, titre);
    strcpy(nouveauLivre->auteur, auteur);
    nouveauLivre->disponible = disponible;
    nouveauLivre->suivant = *liste;
    *liste = nouveauLivre;
}

void afficherLivres(Livre* liste) {
    Livre* courant = liste;
    while (courant != NULL) {
        printf("ID: %d, Titre: %s, Auteur: %s, Disponible: %s\n", courant->id, courant->titre, courant->auteur, courant->disponible ? "Oui" : "Non");
        courant = courant->suivant;
    }
}

void modifierLivre(Livre* liste, int id, const char* nouveauTitre, const char* nouvelAuteur, bool disponible) {
    Livre* courant = liste;
    while (courant != NULL) {
        if (courant->id == id) {
            strcpy(courant->titre, nouveauTitre);
            strcpy(courant->auteur, nouvelAuteur);
            courant->disponible = disponible;
            return;
        }
        courant = courant->suivant;
    }
}

void supprimerLivre(Livre** liste, int id) {
    Livre* courant = *liste;
    Livre* precedent = NULL;
    while (courant != NULL) {
        if (courant->id == id) {
            if (precedent == NULL) {
                *liste = courant->suivant;
            } else {
                precedent->suivant = courant->suivant;
            }
            free(courant);
            return;
        }
        precedent = courant;
        courant = courant->suivant;
    }
}


void empiler(Pile* pile, int idL, int apogeE, const char* dateEm, const char* dateRe) {
    Emprunt* nouvelEmprunt = (Emprunt*)malloc(sizeof(Emprunt));
    nouvelEmprunt->idL = idL;
    nouvelEmprunt->apogeE = apogeE;
    strcpy(nouvelEmprunt->dateEm, dateEm);
    strcpy(nouvelEmprunt->dateRe, dateRe);
    nouvelEmprunt->suivant = pile->sommet;
    pile->sommet = nouvelEmprunt;
}


Emprunt* depiler(Pile* pile) {
    if (pile->sommet == NULL) {
        return NULL;
    }
    Emprunt* empruntDepile = pile->sommet;
    pile->sommet = pile->sommet->suivant;
    return empruntDepile;
}

void afficherEmprunts(Pile* pile) {
    Emprunt* courant = pile->sommet;
    while (courant != NULL) {
        printf("ID Livre: %d, Apogée: %d, Date Emprunt: %s, Date Retour: %s\n", courant->idL, courant->apogeE, courant->dateEm, courant->dateRe);
        courant = courant->suivant;
    }
}

void enfiler(File* file, int idL, int apogeE, const char* dateEm, const char* dateRe) {
    Emprunt* nouvelEmprunt = (Emprunt*)malloc(sizeof(Emprunt));
    nouvelEmprunt->idL = idL;
    nouvelEmprunt->apogeE = apogeE;
    strcpy(nouvelEmprunt->dateEm, dateEm);
    strcpy(nouvelEmprunt->dateRe, dateRe);
    nouvelEmprunt->suivant = NULL;
    if (file->queue == NULL) {
        file->tete = nouvelEmprunt;
    } else {
        file->queue->suivant = nouvelEmprunt;
    }
    file->queue = nouvelEmprunt;
}

Emprunt* defiler(File* file) {
    if (file->tete == NULL) {
        return NULL;
    }
    Emprunt* empruntDefile = file->tete;
    file->tete = file->tete->suivant;
    if (file->tete == NULL) {
        file->queue = NULL;
    }
    return empruntDefile;
}

void afficherFile(File* file) {
    Emprunt* courant = file->tete;
    while (courant != NULL) {
        printf("ID Livre: %d, Apogée: %d, Date Emprunt: %s, Date Retour: %s\n", courant->idL, courant->apogeE, courant->dateEm, courant->dateRe);
        courant = courant->suivant;
    }
}

Noeud* ajouterNoeud(Noeud* racine, Livre livre) {
    if (racine == NULL) {
        Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
        nouveauNoeud->livre = livre;
        nouveauNoeud->gauche = NULL;
        nouveauNoeud->droite = NULL;
        return nouveauNoeud;
    }
    if (livre.id < racine->livre.id) {
        racine->gauche = ajouterNoeud(racine->gauche, livre);
    } else {
        racine->droite = ajouterNoeud(racine->droite, livre);
    }
    return racine;
}


void afficherArbre(Noeud* racine) {
    if (racine != NULL) {
        afficherArbre(racine->gauche);
        printf("ID: %d, Titre: %s, Auteur: %s, Disponible: %s\n", racine->livre.id, racine->livre.titre, racine->livre.auteur, racine->livre.disponible ? "Oui" : "Non");
        afficherArbre(racine->droite);
    }
}

void afficherMenu() {
    printf("\n=== Menu Principal ===\n");
    printf("1. Ajouter un livre\n");
    printf("2. Modifier un livre\n");
    printf("3. Supprimer un livre\n");
    printf("4. Afficher les livres\n");
    printf("5. Emprunter un livre \n");
    printf("6. Retourner un livre \n");
    printf("7. Afficher les emprunts\n");
    printf("8. Ajouter une demande de livraison \n");
    printf("9. Traiter une demande de livraison \n");
    printf("10. Afficher les demandes de livraison\n");
    printf("11. Afficher les livres dans l'arbre\n");
    printf("12. Quitter\n");
}

    Pile pileEmprunts = {NULL};
    File fileLivraisons = {NULL};
    Noeud* arbreLivres = NULL;
    Emprunt* f;
    int choix, id, apogee;
    char titre[50], auteur[50], dateEm[50], dateRe[50];
    bool disponible;
    Emprunt *e ;
    do {
        afficherMenu();
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("ID du livre: ");
                scanf("%d", &id);
                printf("Titre du livre: ");
                scanf("%s", titre);
                printf("Auteur du livre: ");
                scanf("%s", auteur);
                disponible = true;
                ajouterLivre(&listeLivres, id, titre, auteur, disponible);
                Livre livre = {id, titre, auteur, disponible};
                arbreLivres = ajouterNoeud(arbreLivres, livre);
                printf("Livre ajouté avec succès.\n");
                break;

            case 2:
                printf("ID du livre à modifier: ");
                scanf("%d", &id);
                printf("Nouveau titre du livre: ");
                scanf("%s", titre);
                printf("Nouvel auteur du livre: ");
                scanf("%s", auteur);
                printf("Disponibilité (1 pour disponible, 0 pour non disponible): ");
                int dispo;
                scanf("%d", &dispo);
                disponible = dispo;
                modifierLivre(listeLivres, id, titre, auteur, disponible);
                printf("Livre modifié avec succès.\n");
                break;

            case 3:
                printf("ID du livre à supprimer: ");
                scanf("%d", &id);
                supprimerLivre(&listeLivres, id);
                printf("Livre supprimé avec succès.\n");
                break;

            case 4:
                afficherLivres(listeLivres);
                break;

            case 5:
                printf("ID du livre à emprunter: ");
                scanf("%d", &id);
                printf("Apogée de l'étudiant: ");
                scanf("%d", &apogee);
                printf("Date d'emprunt: ");
                scanf("%s", dateEm);
                printf("Date de retour: ");
                scanf("%s", dateRe);
                empiler(&pileEmprunts, id, apogee, dateEm, dateRe);
                printf("Emprunt ajouté avec succès.\n");
                break;

            case 6:
                e =depiler(&pileEmprunts);
                if (e != NULL) {
                    printf("Emprunt dépilé: ID Livre: %d, Apogée: %d\n", e->idL, e->apogeE);
                    free(e);
                } else {
                    printf("La pile d'emprunts est vide.\n");
                }
                break;

            case 7:
                afficherEmprunts(&pileEmprunts);
                break;

            case 8:
                printf("ID du livre pour la demande de livraison: ");
                scanf("%d", &id);
                printf("Apogée de l'étudiant: ");
                scanf("%d", &apogee);
                printf("Date d'emprunt: ");
                scanf("%s", dateEm);
                printf("Date de retour: ");
                scanf("%s", dateRe);
                enfiler(&fileLivraisons, id, apogee, dateEm, dateRe);
                printf("Demande de livraison ajoutée avec succès.\n");
                break;

            case 9:
                f = defiler(&fileLivraisons);
                if (f != NULL) {
                    printf("Demande de livraison traitée: ID Livre: %d, Apogée: %d\n", f->idL, f->apogeE);
                    free(f);
                } else {
                    printf("La file des demandes de livraison est vide.\n");
                }
                break;

            case 10:
                afficherFile(&fileLivraisons);
                break;

            case 11:
                afficherArbre(arbreLivres);
                break;

            case 12:
                printf("Au revoir!\n");
                break;

            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    } while (choix != 12);

    return 0;
}
