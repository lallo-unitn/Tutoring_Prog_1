#include <iostream>
#include <cstdlib>  
using namespace std;

const int DIM = 10;

void remove_rec(float a[], int* n, int to_remove_index);      // rimuove a[i] e shift

int main(){
    float a[DIM] = {0,11,22,33,44,55,66,77,88,99};
    int to_remove_index = 3;                                  
    int counter = DIM;
    remove_rec(a, &counter, to_remove_index);
    for (int j = 0; j < DIM-1; j++)             // stampa a modificato
    {
        cout << a[j] << endl;
    }
    
    return EXIT_SUCCESS;
}

void remove_rec(float a[], int* counter, int to_remove_index){
    if (*counter > to_remove_index)
    {   
        int current_index = DIM - *counter + to_remove_index;
        a[current_index] = a[current_index + 1];
        (*counter)--;
        remove_rec(a, counter, to_remove_index);            // funzione ricorre solo se n > i
    }
    return;
}