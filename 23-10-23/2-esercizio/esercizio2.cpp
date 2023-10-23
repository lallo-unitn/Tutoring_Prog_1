#include<iostream>
#include<cstdlib>
using namespace std;
const int DIM = 10;

void tartaglia(int T[DIM][DIM], int n);     

int main(){
    int T[DIM][DIM];
    tartaglia(T, DIM);
    // stampa matrice
    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++){
            printf("%d\t", T[i][j]);
        }
        cout << endl;
    }
    
    return EXIT_SUCCESS;
}

void tartaglia(int T[DIM][DIM], int n){
    // inizializza a 0
    for (int i = 0; i < n; i++){            
        for (int j = 0; j < n; j++){
            T[i][j] = 0;
        }
    }
    // calcola la matrice
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            // pone a 1 gli elementi sulla diagonale e sulla prima colonna
            if (i == j || j == 0){
                T[i][j] = 1;
                // else, calcola l'elemento secondo la regola di Tartaglia
            }else if(i > j){
                T[i][j] = T[i-1][j-1] + T[i-1][j];
            }
        }
    }
}