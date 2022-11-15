#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

int is_prime(int n);
void fact_scomp(int input);

int main(){
    int input = 0;
    printf("Inserisci un intero maggiore stretto di 1\n");
    scanf("%i", &input);
    while (input <= 1)
    {   
        system("clear");
        printf("Input invalido. \n Inserisci un intero maggiore stretto di 1\n");
        scanf("%i", &input);
    }
    fact_scomp(input);
    return EXIT_SUCCESS;
}

int is_prime(int n){
    int res = TRUE;
    for (int i = 2; i <=  sqrt(n); i++)
    {
        if(n % i == 0) res = FALSE;
    }
    return res;
}

void fact_scomp(int input){
    for (int i = 2; input > 1; i++)
    {
        if(is_prime(i) == TRUE && (input % i) == 0){
            printf("%i  ", i);
            input /= i;
            i--;
        }
    }
    printf("\n");
    return;
}