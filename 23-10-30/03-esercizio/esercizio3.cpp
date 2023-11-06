#include <iostream>
#include "array.h" /* leggi, stampa, MAX_DIM */
using namespace std;

// Inserire qui sotto le DICHIARAZIONI delle funzioni
int main() {
    int array[MAX_DIM];
    int dim;
    cout << "Inserisci il numero di elementi" << endl;
    cin >> dim;
    leggi(array, dim);
    double* normalizzato = normalizza(array, dim);
    cout << "Array normalizzato: " << endl;
    stampa(normalizzato, dim);
    return 0;
}

// Inserire qui sotto le DEFINIZIONI delle funzioni