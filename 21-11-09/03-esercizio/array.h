#ifndef ARRAY_H
#define ARRAY_H

const int MAX_DIM = 1000;

//legge array
void leggi(int array[], int dim);

//funzione ausiliaria
static void leggi_aux(int array[], int dim);

//stampa array
void stampa(double* array, int dim);

//funzione ausiliaria
static void stampa_aux(double* array, int dim);

#endif