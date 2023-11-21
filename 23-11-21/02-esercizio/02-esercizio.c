#include <stdio.h>
#include <string.h>

#define PLACEHOLDER '!'

const int MAX_SIZE = 40;

/* Declare the reverse_array function below */
void reverse_array(char* in, int dim);

int is_lowercase_vowel(char c);

int main() {
    char input[MAX_SIZE];
    printf("Enter string to reverse: ");
    scanf("%s", input);

    /* Assuming strlen(input) < MAX_SIZE always */
    reverse_array(input, strlen(input));

    printf("Reversed array: %s\n", input);
    return 0;
}

/* Define the reverse_array function below */
void reverse_array(char* in, int dim) {
    /* Ends when there are no more characters to copy */
    if (dim > 0) {
        if (is_lowercase_vowel(in[dim - 1]) && is_lowercase_vowel(in[0])) {
            /* Simple case: both ends need to be overwritten */
            in[dim - 1] = in[0] = PLACEHOLDER;
        } else if (is_lowercase_vowel(in[dim - 1])) {
            /* Just save the value of the first element,
               as the last element would be overwritten anyway */
            in[dim - 1] = in[0];
            in[0] = PLACEHOLDER;
        } else if (is_lowercase_vowel(in[0])) {
            /* Just save the value of the last element,
               as the first element would be overwritten anyway */
            in[0] = in[dim - 1];
            in[dim - 1] = PLACEHOLDER;
        } else {
            /* Classic swap */
            char tmp = in[dim - 1];
            in[dim - 1] = in[0];
            in[0] = tmp;
        }

        /* Recursive call */
        reverse_array(in + 1, dim - 2);
    }
}

int is_lowercase_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
