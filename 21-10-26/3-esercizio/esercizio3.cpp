#include<iostream>
#include<cstdlib>
using namespace std;
const int DIM = 10;

// riempie una matrice di dimensione fissata fino al livello n-esimo con i valori del triangolo di Tartaglia-Pascal
void tartaglia(int T[DIM][DIM], int n);     

int main(){
    int T[DIM][DIM];                        // TEST
    tartaglia(T, DIM);
    // stampa matrice
    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++){
            printf("%d\t", T[i][j]);        // alternativa a cout. CFR documentazione online. Potete stampare anche con cout.
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
            if (i == j || j == 0){
                T[i][j] = 1;
            }else if(i > j){
                T[i][j] = T[i-1][j-1] + T[i-1][j];
            }
        }
    }
    return ;
}