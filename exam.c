#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>  // Ajout pour le type bool

typedef struct element {
    int val;
    struct element *suivant;
} element;

typedef element *liste;

// Fonction pour inserer un element a la fin de la liste
void inser_fin(liste *l, int val) {
    element *new_elm = malloc(sizeof(element));
    if (new_elm == NULL) {
        printf("Error\n");
        return;
    }

    new_elm->val = val;
    new_elm->suivant = NULL;

    if (*l == NULL) {
        *l = new_elm;
    } else {
        element *courant = *l;
        while (courant->suivant != NULL) {
            courant = courant->suivant;
        }
        courant->suivant = new_elm;
    }
}

// Fonction pour creer une nouvelle liste a partir de deux listes triees
liste new_miste(liste a, liste b) {
    liste new_liste = NULL;

    element *l1 = a;
    element *l2 = b;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val > l2->val) {
            inser_fin(&new_liste, l1->val);  // Correction: changer inser_fin à inser_fin
            l1 = l1->suivant;
        } else {
            inser_fin(&new_liste, l2->val);
            l2 = l2->suivant;
        }
    }

    while (l1 != NULL) {
        inser_fin(&new_liste, l1->val);
        l1 = l1->suivant;
    }

    while (l2 != NULL) {
        inser_fin(&new_liste, l2->val);
        l2 = l2->suivant;
    }

    return new_liste;
}

// Fonction pour comparer deux listes
bool identique(liste a, liste b) {
    while (a != NULL && b != NULL) {
        if (a->val != b->val) {
            return false;
        }
        a = a->suivant;
        b = b->suivant;
    }
    return (a == NULL && b == NULL);
}

// Fonction pour trouver la valeur minimale dans une liste
int Min(liste l) {
    if (l == NULL) {
        printf("Liste vide\n");
        return INT_MAX;
    }

    element *courant = l;
    int min = courant->val;

    while (courant != NULL) {
        if (courant->val < min) {
            min = courant->val;
        }
        courant = courant->suivant;
    }

    return min;
}

// Fonction pour compter le nombre d'occurrences d'un element dans la liste
int occurences(liste l, int val) {
    element *courant = l;
    int count = 0;

    while (courant != NULL) {
        if (courant->val == val) {
            count++;
        }
        courant = courant->suivant;
    }

    return count;
}

// Fonction pour calculer la moyenne des valeurs dans la liste
float moyenne(liste l) {
    int somme = 0;
    int taille = 0;
    element *courant = l;

    while (courant != NULL) {
        somme += courant->val;
        taille++;
        courant = courant->suivant;
    }

    if (taille == 0) return 0;

    return (float)somme / taille;
}

// Fonction pour afficher la liste
void afficher_liste(liste l) {
    element *courant = l;
    while (courant != NULL) {
        printf("%d -> ", courant->val);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

int main() {
    liste a = NULL;
    liste b = NULL;

    inser_fin(&a, 1);
    inser_fin(&a, 3);
    inser_fin(&a, 5);

    inser_fin(&b, 2);
    inser_fin(&b, 4);  // Correction: changer inser_fin à inser_fin
    inser_fin(&b, 6);

    printf("Liste A: ");
    afficher_liste(a);
    printf("Liste B: ");
    afficher_liste(b);

    liste c = new_miste(a, b);
    printf("Liste fusionnee (triee): ");
    afficher_liste(c);

    printf("Les deux listes sont-elles identiques? %s\n", identique(a, b) ? "Oui" : "Non");

    printf("Le minimum de la liste A: %d\n", Min(a));
    printf("Le nombre d'occurrences de 3 dans la liste A: %d\n", occurences(a, 3));
    printf("La moyenne des valeurs dans la liste A: %.2f\n", moyenne(a));

    return 0;
}