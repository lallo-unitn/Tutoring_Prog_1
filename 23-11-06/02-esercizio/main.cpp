#include <iostream>
using namespace std;

#define DIM 3

void rotate(int matrix[DIM][DIM])
{

    for (int row = 0; row < DIM / 2; row++)
    {
        for (int col = row; col < DIM - row - 1; col++)
        {
            //SWAP ELEMENTS
            int temp = matrix[row][col];
            matrix[row][col] =
                matrix[DIM - 1 - col][row];

            matrix[DIM - 1 - col][row] =
                matrix[DIM - 1 - row][DIM - 1 - col];

            matrix[DIM - 1 - row][DIM - 1 - col] =
                matrix[col][DIM - 1 - row];

            matrix[col][DIM - 1 - row] = temp;
        }
    }
}

void printMatrix(int matrix[DIM][DIM])
{
    for (int row = 0; row < DIM; row++)
    {
        for (int col = 0; col < DIM; col++)
            cout << matrix[row][col] << " ";
        cout << endl;
    }
}

int main()
{   
    int matrix[DIM][DIM] = {{11, 22, 33},
                         {44, 55, 66},
                         {77, 88, 99}};
    printMatrix(matrix);
    cout << endl;
    rotate(matrix);
    printMatrix(matrix);
    return 0;
}