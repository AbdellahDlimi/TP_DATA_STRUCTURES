#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Poly {
    float coef;
    int exp;
    struct Poly *suivant;
} Poly;


Poly *ajouterMonome(Poly *monPoly, float coef, int exp) {
    if (exp < 0) {
        printf("Erreur: exp negatif\n");
        return monPoly;
    }

    Poly *new_poly = malloc(sizeof(Poly));
    if (new_poly == NULL) {
        printf("Erreur d'allocation\n");
        return NULL;
    }

    new_poly->coef = coef;
    new_poly->exp = exp;
    new_poly->suivant = NULL;

    Poly *p = monPoly;
    Poly *prec = NULL;

    while (p != NULL && p->exp > exp) {
        prec = p;
        p = p->suivant;
    }

    if (p != NULL && p->exp == exp) {
        p->coef += coef;
        free(new_poly);
    } else if (prec == NULL) {
        new_poly->suivant = p;
        monPoly = new_poly;
    } else {
        new_poly->suivant = p;
        prec->suivant = new_poly;
    }

    return monPoly;
}

void afficherPoly(Poly *monPoly) {
    Poly *courant = monPoly;
    while (courant != NULL) {
        printf("%.1f*x^%.1d + ", courant->coef, courant->exp);
        courant = courant->suivant;
    }
    printf("->NULL\n\n");
}

Poly *copiePoly(Poly *monPoly) {
    if (monPoly == NULL) {
        return NULL;
    }

    Poly *copie = malloc(sizeof(Poly));
    if (copie == NULL) {
        printf("Erreur d'allocation\n");
        return NULL;
    }

    copie->coef = monPoly->coef;
    copie->exp = monPoly->exp;
    copie->suivant = NULL;

    Poly *p = monPoly->suivant;
    Poly *courant = copie;

    while (p != NULL) {
        Poly *temp = malloc(sizeof(Poly));
        if (temp == NULL) {
            printf("Error\n");
            return NULL;
        }

        temp->coef = p->coef;
        temp->exp = p->exp;
        temp->suivant = NULL;

        courant->suivant = temp;
        courant = courant->suivant;
        p = p->suivant;
    }

    return copie;
}

Poly *sommePoly(Poly *p1, Poly *p2) {
    Poly *SommePly = NULL;

    while (p1 != NULL || p2 != NULL) {
        if (p1 == NULL || (p2 != NULL && p2->exp > p1->exp)) {
            SommePly = ajouterMonome(SommePly, p2->coef, p2->exp);
            p2 = p2->suivant;
        } else if (p2 == NULL || (p1 != NULL && p1->exp > p2->exp)) {
            SommePly = ajouterMonome(SommePly, p1->coef, p1->exp);
            p1 = p1->suivant;
        } else {
            SommePly = ajouterMonome(SommePly, p1->coef + p2->coef, p1->exp);
            p1 = p1->suivant;
            p2 = p2->suivant;
        }
    }
 
    return SommePly;
}

// 👉 Ta fonction originale (pas changée)
Poly *deriverPoly(Poly *monpoly) {
    if (monpoly == NULL) {
        return NULL;
    }

    Poly *dirive_poly = malloc(sizeof(Poly));
    if (dirive_poly == NULL) {
        printf("Error");
        return NULL;
    }

    dirive_poly->coef = monpoly->coef * monpoly->exp;
    dirive_poly->exp = monpoly->exp - 1;

    Poly *p = monpoly->suivant;
    Poly *courant = dirive_poly;

    while (p != NULL) {
        Poly *temp = malloc(sizeof(Poly));
        if (temp == NULL) {
            printf("Error");
            return NULL;
        }

        temp->coef = p->coef * p->exp;
        temp->exp = p->exp - 1;
        temp->suivant = NULL;

        courant->suivant = temp;
        courant = courant->suivant;
        p = p->suivant;
    }

    return dirive_poly;
}

Poly *inverse_Poly(Poly *p) {
    if (p == NULL) {
        return NULL;
    }

    Poly *devant = NULL;
    Poly *milieu = p;
    Poly *derier = NULL;

    while (milieu != NULL) {
        devant = milieu->suivant;
        milieu->suivant = derier;
        derier = milieu;
        milieu = devant;
    }

    return derier;
}

float somPoly(Poly *p1,int x){
    float resultas = 0;
    while(p1 != NULL){
        resultas += p1->coef * pow(p1->exp,x);
        p1 = p1->suivant;
    }
    return resultas ;
}

bool identiquePoly(Poly *p1, Poly *p2) {
    while (p1 != NULL && p2 != NULL) {
        if (p1->coef != p2->coef || p1->exp != p2->exp) {
            return false;
        }
        p1 = p1->suivant;
        p2 = p2->suivant;
    }
        if(p1 == NULL && p2 == NULL){
            return true;
        }else{
            return false;
    }
}
int main() {
    Poly *poly = NULL;

    poly = ajouterMonome(poly, 3, 2);
    poly = ajouterMonome(poly, 2, 1);
    poly = ajouterMonome(poly, 1, 0);

    printf("Polynome original:\n");
    afficherPoly(poly);

    Poly *copie = copiePoly(poly);
    printf("Copie du polynome:\n");
    afficherPoly(copie);

    Poly *derivee = deriverPoly(poly);
    printf("Derivee du polynome:\n");
    afficherPoly(derivee);

    Poly *inverse = inverse_Poly(poly);
    printf("Polynome inverse:\n");
    afficherPoly(inverse);

    float resultas = somPoly(poly, 2);
    printf("Resultat de somPoly: %.1f\n",resultas);

    return 0;
}
