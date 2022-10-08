#include<iostream>
#include<cstdlib>
using namespace std;

int** int_mat_def(int r, int c);
int** int_mat_alloc(int r, int c);
int** compute_prod(int** m1, int r1, int c1, int** m2, int c2);

int main(){
    int r1;
    int c1;
    cout << "Inserisci il numero di righe della prima matrice ";
    cin >> r1;
    cout << endl << "Inserisci il numero di colonne della prima matrice ";
    cin >> c1;
    cout << endl;
    cout << "Inserisci gli elementi della prima matrice" << endl;
    int** m1 = int_mat_def(r1, c1);
    int r2;
    int c2;
    cout << "Inserisci il numero di righe della seconda matrice ";
    cin >> r2;
    cout << endl << "Inserisci il numero di colonne della seconda matrice ";
    cin >> c2;
    cout << endl;
    cout << "Inserisci gli elementi della seconda matrice" << endl;
    int** m2 = int_mat_def(r2, c2);
    cout << endl << "____________________M1____________________" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("%d\t", m1[i][j]);
        }
        cout << endl;
    }
    cout << endl << "____________________M2____________________" << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d\t", m2[i][j]);
        }
        cout << endl;
    }
    
    int** res;
    if(c1 == r2){
        res = compute_prod(m1, r1, c1, m2, c2);
    } else{
        cerr << "Le matrici non sono compatibili" << endl;
        return EXIT_FAILURE;
    }
    cout << endl << "_____________________RES____________________" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d\t", res[i][j]);
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}

int** int_mat_def(int r, int c){
    int** m = new int*[r];
    for (int i = 0; i < r; i++)
    {
        m[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            cout << "[" << i << "][" << j << "] = ";
            cin >> m[i][j];
            cout << endl;
        }
        
    }
    return m;
}

int** compute_prod(int** m1, int r1, int c1, int** m2, int c2){
    int** res = int_mat_alloc(r1, c2);
    int sum = 0;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                sum += m1[i][k]*m2[k][j];
            }
            res[i][j] = sum;
            sum = 0;
        }
    }
    return res;
}

int** int_mat_alloc(int r, int c){
    int** m = new int*[r];
    for (int i = 0; i < r; i++)
    {
        m[i] = new int[c];
    }
    return m;
}