#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int stock;
    struct element *suivant;
} Element;

typedef struct Liste {
    Element *debut;
    Element *fin;
    int taille;
} Liste;

void initListe(Liste *L){
    L->debut = NULL;
    L->fin = NULL;  
    L->taille = 0;
}

void insererDebutListe(Liste *L, int v){
    Element *new_elm = malloc(sizeof(Element));
    if(new_elm == NULL){
        printf("Erreur\n");
        return;
    }

    new_elm->stock = v;
    new_elm->suivant = L->debut;
    L->debut = new_elm;
    if (L->taille == 0) {
        L->fin = new_elm;
    }
    L->taille++;
}

void insererFinListe(Liste *L, int v){
    Element *new_elm = malloc(sizeof(Element));
    if(new_elm == NULL){
        printf("Erreur\n");
        return;
    }

    new_elm->stock = v;
    new_elm->suivant = NULL;

    if(L->debut == NULL){
        L->debut = new_elm;
        L->fin = new_elm;
    } else {
        L->fin->suivant = new_elm;
        L->fin = new_elm;
    }
    L->taille++;
}

void creerListeDecroissante(Liste *L, int n){
    for (int i = n; i >= 0; i--){
        insererDebutListe(L, i);
    }
}

void afficherListe(Liste *L){
    Element *courant = L->debut;
    while(courant != NULL){
        printf("%d -> ", courant->stock);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

void supprimerPremier(Liste *L){
    if(L->debut != NULL){
        Element *temp = L->debut;
        L->debut = L->debut->suivant;
        free(temp);
        L->taille--;
        if (L->debut == NULL){
            L->fin = NULL;
        }
    }
}

void supprimerDernier(Liste *L){
    if(L->debut == NULL){
        return;
    }

    if(L->debut->suivant == NULL){
        free(L->debut);
        L->debut = NULL;
        L->fin = NULL;
        L->taille--;
        return;
    }

    Element *courant = L->debut;
    while(courant->suivant->suivant != NULL){
        courant = courant->suivant;
    }
    Element *a_supprimer = courant->suivant;
    courant->suivant = NULL;
    L->fin = courant;
    free(a_supprimer);
    L->taille--;
}

float moyenne(Liste *L){
    if(L->debut == NULL || L->taille < 1){
        printf("La liste est vide\n");
        return 0;
    }
    Element *courant = L->debut;
    int somme = 0;
    while(courant != NULL){
        somme += courant->stock;
        courant = courant->suivant;
    }
    return (float)somme / L->taille;
}

int rechercheValeur(Liste *L, int valeur){
    Element *courant = L->debut;
    int pos = 0;
    while(courant != NULL){
        if(courant->stock == valeur){
            return pos;
        }
        courant = courant->suivant;
        pos++;
    }
    return -1;
}

int main(){
    int pos;
    Liste liste;
    Liste *maListe = &liste;
    initListe(maListe);

    creerListeDecroissante(maListe, 5);
    printf("Liste initiale\n");
    afficherListe(maListe);

    supprimerPremier(maListe);
    printf("Liste apres suppression du premier element\n");
    afficherListe(maListe);

    supprimerDernier(maListe);
    printf("Liste apres suppression du dernier element\n");
    afficherListe(maListe);

    printf("Moyenne des elements de la liste : %.2f\n", moyenne(maListe));

    insererFinListe(maListe, 10);
    printf("Liste apres ajout de 10 a la fin\n");
    afficherListe(maListe);

    pos = rechercheValeur(maListe, 5);
    if (pos == -1)
        printf("Valeur non trouvee\n");
    else
        printf("Valeur trouvee a la position %d\n", pos);

    return 0;
}
