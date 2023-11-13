#include <stdio.h>
#include <stdlib.h>

int** int_mat_def(int r, int c);
int** int_mat_alloc(int r, int c);
int** compute_prod(int** m1, int r1, int c1, int** m2, int c2);

int main() {
    int r1;
    int c1;
    int r2;
    int c2;
    int i, j, k;

    printf("Inserisci il numero di righe della prima matrice ");
    scanf("%d", &r1);
    printf("\nInserisci il numero di colonne della prima matrice ");
    scanf("%d", &c1);
    printf("\nInserisci gli elementi della prima matrice\n");
    int** m1 = int_mat_def(r1, c1);

    printf("Inserisci il numero di righe della seconda matrice ");
    scanf("%d", &r2);
    printf("\nInserisci il numero di colonne della seconda matrice ");
    scanf("%d", &c2);
    printf("\nInserisci gli elementi della seconda matrice\n");
    int** m2 = int_mat_def(r2, c2);

    printf("\n____________________M1____________________\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("%d\t", m1[i][j]);
        }
        printf("\n");
    }

    printf("\n____________________M2____________________\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d\t", m2[i][j]);
        }
        printf("\n");
    }

    int** res;
    if (c1 == r2) {
        res = compute_prod(m1, r1, c1, m2, c2);
    } else {
        fprintf(stderr, "Le matrici non sono compatibili\n");
        return EXIT_FAILURE;
    }

    printf("\n_____________________RES____________________\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}

int** int_mat_def(int r, int c) {
    int** m = int_mat_alloc(r, c);
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &m[i][j]);
            printf("\n");
        }
    }
    return m;
}

int** compute_prod(int** m1, int r1, int c1, int** m2, int c2) {
    int** res = int_mat_alloc(r1, c2);
    int i, j, k;
    int sum;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            sum = 0;
            for (k = 0; k < c1; k++) {
                sum += m1[i][k] * m2[k][j];
            }
            res[i][j] = sum;
        }
    }
    return res;
}

int** int_mat_alloc(int r, int c) {
    int** m = (int**)malloc(r * sizeof(int*));
    int i;
    for (i = 0; i < r; i++) {
        m[i] = (int*)malloc(c * sizeof(int));
    }
    return m;
}
