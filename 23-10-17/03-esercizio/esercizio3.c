#include <stdio.h>

// Inserire qui le DICHIARAZIONI delle funzioni

int main() {
    int primo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int secondo[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    printf("La somma dei prodotti incrociati dei due array e’ %i \n", somma_prodotto_incrociato(primo, secondo, 10));
    return 0;
}

// Inserire qui le DEFINIZIONI delle funzioni