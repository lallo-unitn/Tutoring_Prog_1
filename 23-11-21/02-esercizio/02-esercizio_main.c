#include <stdio.h>
#include <string.h>

#define SEGNAPOSTO '!'

const int DIMMAX = 40;

int main(int argc, char* argv[]) {
    char input[DIMMAX];
    printf("Enter string to reverse: ");
    scanf("%s", input);

    /* Assuming strlen(input) < DIMMAX always */
    reverse_array(input, strlen(input));

    printf("Reversed array: %s\n", input);
    return 0;
}

