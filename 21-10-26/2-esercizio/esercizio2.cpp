#include<iostream>
#include<cstdlib>
using namespace std;

const int DIM = 6;

// somma i valori puntati dagli elementi degli array

float sum(float* p[], int n);       // versione iterativa
float sum_rec(float* p[], int n);   // versione ricorsiva

int main(){
    float a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;     // TEST
    float* p[DIM];
    p[0] = &a;
    p[1] = &b;
    p[2] = &c;
    p[3] = &d;
    p[4] = &e;
    p[5] = &f;
    cout << "Iterativa: " << sum(p, 4) << endl;
    cout << "Ricorsiva: " << sum_rec(p, 6) << endl;
    return EXIT_FAILURE;
}

float sum(float* p[], int n){
    float sum = 0;
    for (int i = 0; i < n; i++)
    {   
        /*cout << "p[" << i << "] = " << p[i] << endl;      // la sfilza di output serve per esplicare come accedere a: valore, address, reference
        cout << "&p[" << i << "] = " << &p[i] << endl;
        cout << "*p[" << i << "] = " << *p[i] << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<< endl;*/
        sum += *p[i];
    }
    return sum;
}

float sum_rec(float* p[], int n){
    float res = 0;
    if(n > 0){
        res = *p[n-1] + sum_rec(p, --n);    // sommo ricorsivamente i float puntati dagli elementi dell'array
    }
    return res;
}