#include <stdio.h>
#include <stdlib.h>

struct Noeud {
    float donne;
    struct Noeud *suivant;
    struct Noeud *precedent;
};
typedef struct Noeud cellule;
struct liste {
    cellule *debut;
    cellule *fin;
};
typedef struct liste Liste;

void initListe(Liste *L){
    L->debut = NULL;
    L->fin = NULL;
}

void inserut_debut(Liste *l,float val){
    cellule *new_elm = malloc(sizeof(cellule));
    if(new_elm == NULL){
        printf("Error\n");
        return;
    }

    new_elm->donne = val;
    new_elm->suivant = l->debut;
    new_elm->precedent = NULL;
    if(l->debut != NULL){
        l->debut->precedent = new_elm;
    }
    l->debut = new_elm;
    if(l->fin == NULL){
        l->fin = new_elm;
    }
}
void supprimer_fin(Liste *l){
    if(l == NULL){
        return;
    }

    if(l->debut == l->fin){
        free(l->fin);
        l->debut = NULL;
        l->fin = NULL;
        return;
    }

    cellule *temp = l->fin;
    l->fin = l->fin->precedent;
    l->fin->suivant = NULL;
    free(temp);
}

void procedure(Liste *l , int val){
    cellule *courant = l->debut;

    while(courant != NULL){
        if(courant->donne > val){
            cellule *temp = courant;
            courant = courant->suivant;
            
            if(temp == l->debut){
                l->debut = temp->suivant;
                if(l->debut != NULL)
                    l->debut->precedent = NULL;
                else
                    l->fin = NULL; 
            }
            
            else if(temp == l->fin){
                l->fin = temp->precedent;
                l->fin->suivant = NULL;
            }
            
            else {
                temp->precedent->suivant = temp->suivant;
                temp->suivant->precedent = temp->precedent;
            }

            free(temp);
        } else {
            courant = courant->suivant;
        }
    }
    
}



void afficher_liste(Liste *l){
    cellule *courant = l->debut;
    while(courant != NULL){
        printf("%.2f -> ", courant->donne);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

int main() {
    Liste l;
    initListe(&l);
    inserut_debut(&l, 1);
    inserut_debut(&l, 2);
    inserut_debut(&l, 3);
    inserut_debut(&l, 4);
    inserut_debut(&l, 5);
    inserut_debut(&l, 6);
    inserut_debut(&l, 7);
    inserut_debut(&l, 8);
    inserut_debut(&l, 9);
    afficher_liste(&l);
    supprimer_fin(&l);
    afficher_liste(&l);
    procedure(&l, 5);
    afficher_liste(&l);
    return 0;
}





