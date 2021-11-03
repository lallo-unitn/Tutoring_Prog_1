#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int DIM = 10;

//calcola la media di un campione ricorsivamente
double mean_rec(double x[], int n);

//calcola la somma di un array ricorsivamente
double sum_rec(double x[], int n);

//calcola la deviazione standard di un campione ricorsivamente
double std_deviation_rec(double x[], int n);

//funzione ausiliaria a 
//double std_deviation_rec(double x[], int n);
double std_deviation_rec_aux(double x[], int n, double media);

int main(){
    double x[DIM] = {0,11,22,33,44,55,66,77,88,99};
    double s = std_deviation_rec(x, DIM);
    cout << "s = " << s << endl;
    return EXIT_SUCCESS;
}

double std_deviation_rec(double x[], int n){
    double sigma = 0;
    double media = mean_rec(x, n);
    return sqrt( std_deviation_rec_aux(x, n, media) / (n-1) );
}

double std_deviation_rec_aux(double x[], int n, double media){
    float res = 0;
    if(n > 0){
        res = pow(x[n] - media, 2) + std_deviation_rec_aux(x, --n, media);
    }
    return res;
}

double mean_rec(double x[], int n){
    return sum_rec(x, n)/n;
}

double sum_rec(double x[], int n){
    float res = 0;
    if(n > 0){
        res = x[n-1] + sum_rec(x, --n);
    }
    return res;
}