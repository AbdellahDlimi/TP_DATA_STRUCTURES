#include <stdio.h>
#include <stdlib.h>

struct element {
    int x;
    int y;
    struct element *precedent;
};
typedef struct element *sommet;

void Empiler(sommet *pile, int x, int y) {
    sommet new_elem = malloc(sizeof(struct element));
    if (new_elem == NULL) {
        printf("Erreur d'allocation\n");
        return;
    }
    new_elem->x = x;
    new_elem->y = y;
    new_elem->precedent = *pile;
    *pile = new_elem;
}

void depiler(sommet *pile) {
    if (*pile != NULL) {
        sommet temp = *pile;
        *pile = (*pile)->precedent;
        free(temp);
    }
}

int labyrinthe(sommet *pile, int l, int M[l][l], int i, int j) {
    int x, y;
    int cpt = 0;

    Empiler(pile, i, j);

    while (*pile != NULL) {
        x = (*pile)->x;
        y = (*pile)->y;
        depiler(pile);

        if (x == l - 1 && y == l - 1) {
            cpt++;
            continue;
        }

        if (x < l - 1 && M[x + 1][y] != -1) {
            Empiler(pile, x + 1, y);
        }

        if (y < l - 1 && M[x][y + 1] != -1) {
            Empiler(pile, x, y + 1);
        }
    }

    return cpt;
}

int main() {
    int mat[3][3] = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    sommet pile = NULL;
    int chemins = labyrinthe(&pile, 3, mat, 0, 0);
    printf("Nombre de chemins : %d\n", chemins);

    return 0;
}
