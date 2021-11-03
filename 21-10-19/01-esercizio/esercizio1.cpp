/*  Scrivere un programma che legga una stringa [char input[DIM] ] da stdin e la stampi al contrario. Questo deve essere implementato
    attraverso due funzioni che fanno essenzialmente la stessa cosa, ma una funziona ricorsivamente e una iterativamente.
    Le firme sono:
        void stampa_iterativa(char* input);
        void stampa_ricorsiva(char* input);
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

const int DIM = 100;

int stampa_iterativa(char* input);
void stampa_ricorsiva(char* input);
void stampa_ricorsiva_aux(char* input, int count);

int main(){
    char input[DIM];
    cout << "Inserisci stringa: ";
    cin >> input;
    cout << endl;
    stampa_iterativa(input);
    stampa_ricorsiva(input);
    return EXIT_SUCCESS;
}

int stampa_iterativa(char* input){
    int length = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        length++;
    }
    for (int i = length; i >= 0; i--)
    {
        cout << input[i];
    }
    cout << endl;
    return EXIT_SUCCESS;
}


void stampa_ricorsiva(char* input){
    stampa_ricorsiva_aux(input, 0);
    cout << endl;
    return;
}

void stampa_ricorsiva_aux(char* input, int count){
    if(input[count] != '\0'){
        count++;
        stampa_ricorsiva_aux(input, count);
        count--;
        cout << input[count];
    }
    return;
}