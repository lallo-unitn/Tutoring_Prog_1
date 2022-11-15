#include <iostream>
using namespace std;

long somma_prodotto_incrociato(int a[], int b[], int dim);
long somma_prodotto_incrociato_ric(int a[], int b[], int primo, int ultimo);

int main() {
    int primo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int secondo[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    cout << "La somma dei prodotti incrociati dei due array e’ " << somma_prodotto_incrociato(primo, secondo, 10) << endl;
    return 0;
}

long somma_prodotto_incrociato(int a[], int b[], int dim) {
    return somma_prodotto_incrociato_ric(a, b, 0, dim - 1);
}
long somma_prodotto_incrociato_ric(int a[], int b[], int primo, int ultimo) {
    long ris = 0;
    if(ultimo >= 0){
        ris = (a[primo] * b[ultimo]) + somma_prodotto_incrociato_ric(a, b, primo + 1, ultimo - 1);
    }
    return ris;
}