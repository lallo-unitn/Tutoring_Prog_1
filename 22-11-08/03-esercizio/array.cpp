#include <iostream>
#include "array.h"
using namespace std;

//legge array
void leggi(int array[], int dim){
    cout << "Inserisci elemento "<< endl;
    return leggi_aux(array, --dim);
}

static void leggi_aux(int array[], int dim){
    if(dim > 0){
        dim--;
        leggi_aux(array, dim);
        dim++;
    }
    cout << "[ " << dim << " ] = ";
    cin >> array[dim];
    cout << endl;
    return ;
}

//stampa array
void stampa(double* array, int dim){
    return stampa_aux(array, --dim);
}

static void stampa_aux(double* array, int dim){
    if(dim > 0){
        dim--;
        stampa_aux(array, dim);
        dim++;
    }
    cout << "[ " << dim << " ] = " << array[dim];
    cout << endl;
    return ;
}