#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NMaxL 81
#define ASCIIcapLetters ('A' - 'a')

int main(int argc, char* argv[]) {
    FILE *myin, *myout;

    if (argc != 3) {
        fprintf(stderr, "Error, usage: %s <sourcefile> <targetfile>\n", argv[0]);
        exit(1);
    }

    myin = fopen(argv[1], "r");
    myout = fopen(argv[2], "w");

    if (myin == NULL) {
        fprintf(stderr, "Error: %s does not exist\n", argv[1]);
        exit(1);
    }

    char stringa[NMaxL];
    int nextup = 1;

    while (fscanf(myin, "%s", stringa) != EOF) {
        if (nextup) {
            if (stringa[0] >= 'a' && stringa[0] <= 'z') {
                stringa[0] += ASCIIcapLetters;
            }
        }

        int len = strlen(stringa);
        if (stringa[len - 1] == '!' || stringa[len - 1] == '?' || stringa[len - 1] == '.') {
            nextup = 1;
            fprintf(myout, "%s\n", stringa);
        } else {
            nextup = 0;
            fprintf(myout, "%s ", stringa);
        }
    }

    fclose(myin);
    fclose(myout);

    return 0;
}
