#include<iostream>
#include<cstdlib>
using namespace std;

const int DIM = 3;

//Ritorna il prodotto esterno dei primi tre elementi di a e b.
void outerProduct3(float p[][DIM], float a[], float b[]);

int main(){
    float a[DIM] = {2.2,3.3,4.4};
    float b[DIM] = {2.0,-1.0,0.0};
    float p[DIM][DIM] = {0};
    outerProduct3(p, a, b);
    for (int i = 0; i < DIM; i++){                  //stampa matrice
        for (int j = 0; j < DIM; j++){
            cout << p[i][j] << "  ";
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}

void outerProduct3(float p[][DIM], float a[], float b[]){
    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++){
            p[i][j] = a[i]*b[j];
        }
    }
    return ;
}