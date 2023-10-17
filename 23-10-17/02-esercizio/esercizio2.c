#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

const int DIM = 6;

float sum(float* p[], int n, bool* errorFlag);

int main(){
    float a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
    float* p[DIM];
    bool errorFlag = false;
    p[0] = &a;
    p[1] = &b;
    p[2] = &c;
    p[3] = &d;
    p[4] = &e;
    p[5] = &f;
    int n = 0;
    printf("Inserisci il numero di elementi da sommare: \n");
    scanf("%i", &n);
    float res = sum(p, n, &errorFlag);
    if(!errorFlag){
        printf("result = %f \n", res);
    } else{
        printf("Errore: out of bound \n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

float sum(float* p[], int n, bool* errorFlag){
    // TODO: implement
}