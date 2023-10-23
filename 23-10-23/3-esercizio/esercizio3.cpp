#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

const int DIM = 10;

// calcola la media
double mean(double x[], int n);

// calcola la deviazione standard di un campione
double std_deviation(double x[], int n);

int main(){
    double x[DIM] = {0,11,22,33,44,55,66,77,88,99};         // TEST
    double s = std_deviation(x, DIM);
    cout << "s = " << s << endl;
    return EXIT_SUCCESS;
}

double std_deviation(double x[], int n){
    double sigma = 0;
    double media = mean(x, n);          // calcola la media
    for (int i = 0; i < n; i++)
    {
        sigma += pow(x[i] - media, 2);  // calcola la sommatoria
    }
    return sqrt(sigma/(n-1));           // divide la sommatoria e ne calcola la radice
}

double mean(double x[], int n){
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += x[i];
    }
    return sum/n;
}