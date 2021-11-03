#include<iostream>
#include<cstdlib>
using namespace std;

const int DIM = 6;

float sum(float* p[], int n);

int main(){
    float a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
    float* p[DIM];
    p[0] = &a;
    p[1] = &b;
    p[2] = &c;
    p[3] = &d;
    p[4] = &e;
    p[5] = &f;
    cout << sum(p, 3) << endl;
    return EXIT_FAILURE;
}

float sum(float* p[], int n){
    float sum = 0;
    for (int i = 0; i < n; i++)
    {   
        cout << "p[" << i << "] = " << p[i] << endl;
        cout << "&p[" << i << "] = " << &p[i] << endl;
        cout << "*p[" << i << "] = " << *p[i] << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<< endl;
        sum += *p[i];
    }
    return sum;
}