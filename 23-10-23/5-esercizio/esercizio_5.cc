#include <iostream>
using namespace std;
const int MAX_PRIMI = 100;
//lista dei primi compresi tra 0 e 541
const int CENTO_PRIMI[MAX_PRIMI] ={  2,   3,   5,   7,  11,  13,  17,  19,  23,  29, 31,  37,  41,  43,  47,  53,  59,  61,  67,  71,73,  79,  83,  89,  97, 101, 103, 107, 109, 113,127, 131, 137, 139, 149, 151, 157, 163, 167, 173,179, 181, 191, 193, 197, 199, 211, 223, 227, 229,233, 239, 241, 251, 257, 263, 269, 271, 277, 281,283, 293, 307, 311, 313, 317, 331, 337, 347, 349,353, 359, 367, 373, 379, 383, 389, 397, 401, 409,419, 421, 431, 433, 439, 443, 449, 457, 461, 463,467, 479, 487, 491, 499, 503, 509, 521, 523, 541};

//Primality test. Restituisce
//  __ 1 se il numero inserito è primo
//  __ 0 se il numero inserito non è primo
//  __ -1 se non è possibile dare una risposta
int primo(int n);

//Funzione ausiliaria a
//int primo(int n);
int cento_primi_rec(int n, int depth);

int main(){
    int n,ris;
    do {
        cout << "Introdurre un numero intero > 1: ";
        cin >> n;
        if (n <= 1)cerr << "Il numero e’ troppo piccolo." << endl;
        else {
            ris = primo(n);
            if(ris < 0) cout << "Non sono riuscito a stabilire se " << n << " e’ primo\n";
            else cout << n << ((ris > 0) ? "" : " non") << " e’ primo." << endl;
        }
    }while(n > 1);

    return (0);
}

int primo(int n){
    int res;
    int depth{0};
    res = cento_primi_rec(n,depth);
    return res;
}

int cento_primi_rec(int n, int indice) {
    int ris;
    if (indice >= MAX_PRIMI) ris = -1; 
    
    else if (n == CENTO_PRIMI[indice]) ris = 1;

    else if ((n % CENTO_PRIMI[indice]) == 0) ris = 0;

    else {
        ris = cento_primi_rec(n, indice+1);
    }

    return ris;
}