#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define MAX_LENGTH 8

/* Function to encode a number as per specified rules */
int encode(char* number) {
    int base = 1;
    int result = 0;
    int i;
    for (i = strlen(number) - 1; i >= 0; i--) {
        if (number[i] >= '0' && number[i] <= '9') {
            result += (number[i] - '0') * base;
        } else if (number[i] >= 'a' && number[i] <= 'z') {
            int value = 10 + (number[i] - 'a');
            result += value * base;
        }
        base = base * 36;
    }

    return result;
}

/* Function to decode a number as per specified rules */
void decode(int coded, char* decoded) {
    int i = 0;

    while (coded != 0) {
        int modulo = coded % 36;
        coded = (coded - modulo) / 36;

        if (modulo < 10) {
            decoded[i] = '0' + modulo;
        } else {
            decoded[i] = 'a' + modulo - 10;
        }
        i++;
    }
    decoded[i] = '\0';
    int j;
    for (j = 0; j < i / 2; j++) {
        char tmp = decoded[j];
        decoded[j] = decoded[i - 1 - j];
        decoded[i - 1 - j] = tmp;
    }
}

/* Main function */
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: exercise1.out <input> <output>\n");
        exit(1);
    }

    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    if (input == NULL || output == NULL) {
        printf("Error opening streams!\n");
        exit(1);
    }

    printf("This program encodes a text word by word, adding the encoding key to each word.\n"
           "Words are decoded as numbers in base 36, with ten digits 0...9 and twenty-six characters a...z.\n"
           "Where 0->0, a->10, z->35, 10->36, 1z->71, 20->72\n");

    char buffer[MAX_LENGTH];

    int key = 1;
    while (1) {
        printf("Enter a number to use as an encryption key (up to 7 digits): ");
        scanf("%s", buffer);
        if (strlen(buffer) <= 7)
            break;
    }
    key = atoi(buffer);
    printf("%d\n", key);

    while (fscanf(input, "%s", buffer) != EOF) {
        printf("%s", buffer);
        buffer[4] = '\0';

        int encoded;
        encoded = encode(buffer);
        printf(" (%d) ", encoded);

        encoded += key;
        decode(encoded, buffer);
        printf(" -> encrypted %s (%d) ", buffer, encoded);
        fprintf(output, "%s ", buffer);

        encoded = encode(buffer) - key;
        decode(encoded, buffer);
        printf(" -> decrypted %s (%d)\n", buffer, encoded);
    }

    fclose(input);
    fclose(output);

    return 0;
}
