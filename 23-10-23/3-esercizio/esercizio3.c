#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 10

double mean(double x[], int n);
double std_deviation(double x[], int n);

int main(){
    double x[DIM] = {0,11,22,33,44,55,66,77,88,99};
    double s = std_deviation(x, DIM);
    printf("s = %lf\n", s);
    return EXIT_SUCCESS;
}

double std_deviation(double x[], int n){
    double sigma = 0;
    double media = mean(x, n);

    for (int i = 0; i < n; i++){
        sigma += pow(x[i] - media, 2);
    }

    return sqrt(sigma / (n - 1));
}

double mean(double x[], int n){
    double sum = 0;

    for (int i = 0; i < n; i++){
        sum += x[i];
    }

    return sum / n;
}
