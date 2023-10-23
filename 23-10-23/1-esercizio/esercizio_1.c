#include <stdio.h>
#include <stdlib.h>

#define DIM 10

void remove_rec(float a[], int* n, int to_remove_index);  // Remove a[i] and shift

int main() {
    float a[DIM] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99};
    int to_remove_index = 3;
    int counter = DIM;
    remove_rec(a, &counter, to_remove_index);

    for (int j = 0; j < DIM - 1; j++) {
        printf("%f\n", a[j]);
    }

    return EXIT_SUCCESS;
}

void remove_rec(float a[], int* counter, int to_remove_index) {
    if (*counter > to_remove_index) {
        int current_index = DIM - *counter + to_remove_index;
        a[current_index] = a[current_index + 1];
        (*counter)--;
        remove_rec(a, counter, to_remove_index); // Recurse only if counter > to_remove_index
    }
    return;
}
