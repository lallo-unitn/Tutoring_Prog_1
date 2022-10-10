#include<stdio.h>
#include<stdlib.h>

int cmp(char* s1, char* s2);

const int N = 5;

int main(){
    char s1[] = "prova";
    char s2[] = "prova";
    printf("Test1 = %i\n", cmp(s1, s2));
    s1[4] = 'b';
    printf("Test2 = %i\n", cmp(s1, s2));
    s2[4] = 'c';
    printf("Test3 = %i\n", cmp(s1, s2));
    return EXIT_SUCCESS;
}

int cmp(char* s1, char* s2){
    int res = -2;
    for (int i = 0; i < N; i++)
    {
        if(s1[i] < s2[i]){
            res = -1;
        }
        else if(s1[i] > s2[i]){
            res = 1;
        }else if(s1[i] == s2[i]){
            res = 0;
        }
    }
    return res;
}