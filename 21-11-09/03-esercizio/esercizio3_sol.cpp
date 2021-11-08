#include <iostream>
#include "array.h" /* leggi, stampa, MAX_DIM */
using namespace std;

double calcola_norma_ricorsivo(int arr[], int n, int sum);
void dividi_ricorsivo(int source[], double dest[], double norma, int n);
double* normalizza(int source[], int dim);

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

double calcola_norma_ricorsivo(int arr[], int n, int sum) {
    double res;
    if (n < 0) {
        res = sum;
    } else {
        sum += arr[n];
        res = calcola_norma_ricorsivo(arr, n - 1, sum);
    }
    return res;
}

void dividi_ricorsivo(int source[], double dest[], double norma, int n) {
    if (n >= 0) {
        dest[n] = source[n] / norma;
        dividi_ricorsivo(source, dest, norma, n - 1);
    }
    return ;
}

double* normalizza(int source[], int dim) {
    double* normalizzato = new double[dim];
    double norma = calcola_norma_ricorsivo(source, dim - 1, 0);
    dividi_ricorsivo(source, normalizzato, norma, dim - 1);
    return normalizzato;
}