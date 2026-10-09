#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    char donnec;
    struct element *precedent;
} Element;

typedef struct pile {
    Element *debut;
    int taille;
} Pile;

// Initialisation de la pile
void initialiser(Pile *p) {
    p->debut = NULL;
    p->taille = 0;
}

// Empiler un caractère
int empiler(Pile *p, char c) {
    Element *nouveau = (Element*)malloc(sizeof(Element));
    if (nouveau == NULL) return 0;

    nouveau->donnec = c;
    nouveau->precedent = p->debut;
    p->debut = nouveau;
    p->taille++;
    return 1;
}

// Dépiler un caractère
void depiler(Pile *p) {
    if (p->debut == NULL) return;

    Element *aSupprimer = p->debut;
    p->debut = p->debut->precedent;
    free(aSupprimer);
    p->taille--;
}

// Afficher la pile
void affiche(Pile *p) {
    Element *courant = p->debut;
    printf("Pile (taille=%d): ", p->taille);
    while (courant != NULL) {
        printf("%c ", courant->donnec);
        courant = courant->precedent;
    }
    printf("\n");
}

// ✅ Vérification des parenthèses dans un fichier
void verifierParentheses(FILE *f) {
    Pile s;
    initialiser(&s);
    unsigned num_ligne = 1, num_col = 0;
    char c;

    while ((c = fgetc(f)) != EOF) {
        num_col++;
        if (c == '\n') {
            num_ligne++;
            num_col = 0;
            continue;
        }

        switch (c) {
            case '(':
            case '[':
            case '{':
                empiler(&s, c);
                break;

            case ')':
                if (s.taille == 0 || s.debut->donnec != '(') {
                    printf("Erreur: ')' inattendu ligne %u, colonne %u\n", num_ligne, num_col);
                } else {
                    depiler(&s);
                }
                break;

            case ']':
                if (s.taille == 0 || s.debut->donnec != '[') {
                    printf("Erreur: ']' inattendu ligne %u, colonne %u\n", num_ligne, num_col);
                } else {
                    depiler(&s);
                }
                break;

            case '}':
                if (s.taille == 0 || s.debut->donnec != '{') {
                    printf("Erreur: '}' inattendu ligne %u, colonne %u\n", num_ligne, num_col);
                } else {
                    depiler(&s);
                }
                break;
        }
    }

    if (s.taille != 0) {
        printf("Erreur: %d parenthèse(s) non fermée(s).\n", s.taille);
        // Vider la pile
        while (s.taille != 0) depiler(&s);
    }
}

// ✅ Test global
int main() {
    printf("=== Test pile simple ===\n");
    testPile();

    printf("\n=== Vérification des parenthèses ===\n");
    FILE *f = fopen("test.txt", "r");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier test.txt\n");
        return 1;
    }

    verifierParentheses(f);
    fclose(f);
    return 0;
}
