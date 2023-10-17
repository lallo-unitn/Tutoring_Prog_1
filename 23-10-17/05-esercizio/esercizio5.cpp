#include<iostream>
#include<cstdlib>
using namespace std;

int cmp(char* s1, char* s2);

const int N = 5;

int main(){
    char s1[] = "prova";
    char s2[] = "prova";
    cout << "Test1 = " << cmp(s1, s2) << endl;
    s1[4] = 'b';
    cout << "Test2 = " << cmp(s1, s2) << endl;
    s2[4] = 'c';
    cout << "Test3 = " << cmp(s1, s2) << endl;
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