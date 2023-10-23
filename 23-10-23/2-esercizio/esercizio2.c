#include <stdio.h>
#include <stdlib.h>
const int DIM = 10;

void tartaglia(int T[DIM][DIM], int n);

int main() {
    int T[DIM][DIM];
    tartaglia(T, DIM);

    // Print the matrix
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            printf("%d\t", T[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}

void tartaglia(int T[DIM][DIM], int n) {
    // Initialize to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[i][j] = 0;
        }
    }

    // Calculate the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Set elements on the diagonal and the first column to 1
            if (i == j || j == 0) {
                T[i][j] = 1;
            }
            // Calculate other elements based on Tartaglia's rule
            else if (i > j) {
                T[i][j] = T[i - 1][j - 1] + T[i - 1][j];
            }
        }
    }
}
