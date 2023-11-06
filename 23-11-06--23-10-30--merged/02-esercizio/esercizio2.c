#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAROLE 10000
#define MAX_LUNGHEZZA 101

int strlen_c(const char *parola) {
    int contatore = 0;
    while (parola[contatore] != '\0')
        contatore++;
    return contatore;
}

int main(int argc, char *argv[]) {
    char parole[MAX_PAROLE][MAX_LUNGHEZZA];
    int totale_parole = 0;


    if (argc != 3) {
        printf("Usage: esercizio2 <input_file> <output_file>\n");
        exit(1);
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    if (input == NULL) {
        printf("Non sono riuscito ad aprire il file %s\n", argv[1]);
        exit(1);
    }

    char buffer[MAX_LUNGHEZZA];
    while (fscanf(input, "%s", buffer) != EOF) {
        int lunghezza = strlen_c(buffer);
        if (lunghezza % 2 == 0) {
            strncpy(parole[totale_parole], buffer, lunghezza);
            parole[totale_parole][lunghezza] = '\0';
            totale_parole++;
        }
    }
    int i;
    for (i = totale_parole - 1; i >= 0; i--) {
        fprintf(output, "%s ", parole[i]);
    }
    fprintf(output, "\n");

    fclose(input);
    fclose(output);

    return 0;
}
