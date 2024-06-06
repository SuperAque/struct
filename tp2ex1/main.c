#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

typedef Node* pile;

pile Initialiser() {
    return NULL;
}

int AccederSommet(pile P, int *pelem) {
    if (P == NULL) {
        return 1;
    }
    *pelem = P->data;
    return 0;
}

void Empiler(pile* pP, int elem){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL){
		printf("erreur d'allocation de mémoire:\n");
	exit(1);

	}
	newNode -> data = elem;
	newNode -> next = *pP;
	*pP = newNode;
}

int Depiler(pile *pP, int *pelem){
	 if (*pP == NULL) {
        return 1;
    }
    Node* temp = *pP;
    *pelem = temp->data;
    *pP = (*pP)->next;
    free(temp);
    return 0;
}

void Affichage(pile *pP){
	Node* current = *pP;
	if(current == NULL)
		printf("la pile est vide\n");
	else{
	    while(current != NULL){
	    	printf("%d \n", current -> data);
			current = current -> next;
	    }
	}
	printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud de la liste chaînée
typedef struct Node {
    int data;            // Donnée du nœud
    struct Node* next;   // Pointeur vers le nœud suivant
} Node;

// Définition de la pile comme étant un pointeur vers un nœud
typedef Node* Pile;

// Fonction pour créer une pile vide
Pile Initialiser() {
    return NULL;  // Une pile vide est représentée par un pointeur NULL
}

// Fonction pour accéder au sommet de la pile
int AccederSommet(Pile P, int *pelem) {
    if (P == NULL) {
        return 1;  // Erreur: la pile est vide
    }
    *pelem = P->data;  // Récupère la valeur au sommet de la pile
    return 0;          // Succès
}

// Fonction pour empiler des entiers dans la pile
void Empiler(Pile* pP, int elem) {
    // Alloue de la mémoire pour un nouveau nœud
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur: allocation mémoire échouée\n");
        exit(1);  // Termine le programme en cas d'erreur d'allocation
    }
    newNode->data = elem;  // Initialise le nouveau nœud
    newNode->next = *pP;   // L'ancien sommet devient le suivant du nouveau nœud
    *pP = newNode;         // Le nouveau nœud devient le sommet de la pile
}

// Fonction pour dépiler (supprimer le sommet de la pile)
int Depiler(Pile* pP, int *pelem) {
    if (*pP == NULL) {
        return 1;  // Erreur: la pile est vide
    }
    Node* temp = *pP;       // Temporaire pour stocker le sommet
    *pelem = temp->data;    // Récupère la valeur au sommet de la pile
    *pP = (*pP)->next;      // Le sommet suivant devient le nouveau sommet
    free(temp);             // Libère la mémoire du nœud supprimé
    return 0;               // Succès
}

// Fonction pour afficher les éléments de la pile
void Affichage(Pile* pP) {
    Node* current = *pP;  // Commence au sommet de la pile
    if (current == NULL) {
        printf("La pile est vide\n");
        return;
    }
    printf("Éléments de la pile : ");
    while (current != NULL) {
        printf("%d ", current->data);  // Affiche la donnée du nœud actuel
        current = current->next;       // Passe au nœud suivant
    }
    printf("\n");
}

// Exemple d'utilisation
int main() {
    Pile maPile = Initialiser();  // Crée une pile vide

    // Empiler des éléments
    Empiler(&maPile, 10);  // Empile l'entier 10
    Empiler(&maPile, 20);  // Empile l'entier 20
    Empiler(&maPile, 30);  // Empile l'entier 30

    // Afficher les éléments de la pile
    Affichage(&maPile);

    // Accéder au sommet de la pile
    int sommet;
    if (AccederSommet(maPile, &sommet) == 0) {
        printf("Le sommet de la pile est : %d\n", sommet);
    } else {
        printf("Erreur: la pile est vide\n");
    }

    // Dépiler les éléments
    while (Depiler(&maPile, &sommet) == 0) {
        printf("Dépilé : %d\n", sommet);
    }

    // Afficher les éléments de la pile après dépilement
    Affichage(&maPile);

    return 0;
}









