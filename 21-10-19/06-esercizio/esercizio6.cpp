#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

bool is_prime(int n);
void fact_scomp(int input);

int main(){
    int input = 0;
    cout << "Inserisci un intero maggiore stretto di 0" << endl;
    cin >> input;
    fact_scomp(input);
    return EXIT_SUCCESS;
}

bool is_prime(int n){
    bool res = true;
    for (int i = 2; i <=  sqrt(n); i++)
    {
        if(n % i == 0) res = false;
    }
    return res;
}

void fact_scomp(int input){
    for (int i = 2; input > 1; i++)
    {
        if(is_prime(i) && (input % i) == 0){
            cout << i << "  ";
            input /= i;
            i--;
        }
    }
    cout << endl;
    return;
}