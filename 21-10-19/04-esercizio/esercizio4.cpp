#include<iostream>
#include<cstdlib>
using namespace std;

const int DIM = 9;

void rotate(int a[], int n, int k);

int main(){
    
    for (int i = -DIM + 1; i < DIM; i++)
    {
        int array[DIM] = {11,22,33,44,55,66,77,88,99};
        rotate(array, DIM, i);
        cout << "Traslazioni: " << i << "  array: ";
        for (int j = 0; j < DIM; j++)
        {
            cout << array[j] << " ";
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}

void rotate(int a[], int n, int k){
    if(k >= 0){
        for (int i = 0; i < k; i++)
        {
            int tmpN = a[n-1];
            int temp1 = a[0];
            int temp2 = a[1];
            for (int j = 0; j < n-1; j++)
            {   
                a[j+1] = temp1;
                temp1 = temp2;
                temp2 = a[j+2];
            }
            a[0] = tmpN;
        }
    } else{
        k = abs(k);
        for (int i = 0; i < k; i++)
        {
            int tmp0 = a[0];
            for (int j = 0; j < n-1; j++)
            {   
                a[j] = a[j+1];
            }
            a[n-1] = tmp0;
        }
    }
    return;
}