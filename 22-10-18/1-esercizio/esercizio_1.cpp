#include <iostream>
#include <cstdlib>  
using namespace std;

const int DIM = 10;

void remove_rec(float a[], int& n, int i);      // rimuove a[i] e shifta

int main(){                                     // di seguito un test per remove_rec(a, DIM, 9);
    float a[DIM] = {0,11,22,33,44,55,66,77,88,99};
    int i = 8;                                  
    int n = DIM;
    remove_rec(a, n, i);
    for (int j = 0; j < DIM-1; j++)             // stampa a modificato
    {
        cout << a[j] << endl;
    }
    
    return EXIT_SUCCESS;
}

void remove_rec(float a[], int& n, int i){
    if (n > i)
    {   
        a[DIM-n+i] = a[DIM-n+i+1];
        n--;
        remove_rec(a, n, i);            // reitera funzione solo se n > i
    }
    return;                             // altrimenti, ritorna
}