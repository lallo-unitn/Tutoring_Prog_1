#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 10

double mean_rec(double x[], int n);
double sum_rec(double x[], int n);
double std_deviation_rec(double x[], int n);
double std_deviation_rec_aux(double x[], int n, double media);

int main(){
    double x[DIM] = {0,11,22,33,44,55,66,77,88,99};
    double s = std_deviation_rec(x, DIM);
    printf("s = %lf\n", s);
    return EXIT_SUCCESS;
}

double std_deviation_rec(double x[], int n){
    double sigma = 0;
    double media = mean_rec(x, n);
    return sqrt(std_deviation_rec_aux(x, n, media) / (n-1));
}

double std_deviation_rec_aux(double x[], int n, double media){
    double res = 0;
    if(n > 0){
        res = pow(x[n-1] - media, 2) + std_deviation_rec_aux(x, n-1, media);
    }
    return res;
}

double mean_rec(double x[], int n){
    return sum_rec(x, n) / n;
}

double sum_rec(double x[], int n){
    double res = 0;
    if(n > 0){
        res = x[n-1] + sum_rec(x, n-1);
    }
    return res;
}
