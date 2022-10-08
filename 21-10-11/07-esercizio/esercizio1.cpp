#include <cstdio>
#include <iostream>
using namespace std;

#define ROW 7
#define COLUMN 7

void initBoard(char matrix[ROW][COLUMN]){
    char slotNumber = '1';
    for (unsigned int i = 0; i < COLUMN; i++)
    {
        for (unsigned int j = 0; j < ROW; j++)
        {
            if(i%2 == 0){
                matrix[j][i] = '-';
            } else if(j%2 == 0){
                matrix[j][i] = '|';
            }else{
                matrix[j][i] = slotNumber;
                slotNumber++;;
            }
        }   
    }
}

void printBoard(char matrix[ROW][COLUMN]){
    for (unsigned int i = 0; i < COLUMN; i++)
    {
        for (unsigned int j = 0; j < ROW; j++)
        {
            cout << matrix[j][i];
        }
        cout << endl;
    }
}

bool setBoardCell(char matrix[ROW][COLUMN], char input, char turn, unsigned int *row, unsigned int *col){
    bool isInputValid = false;
    if(input < '1' || input > '9') return isInputValid;
    for (unsigned int i = 0; i < ROW; i++)
    {
        for (unsigned int j = 0; j < COLUMN; j++)
        {
            if(matrix[i][j] == input){
                matrix[i][j] = turn;
                isInputValid = true;
                *row = i;
                *col = j;
            }
        }   
    }
    return isInputValid;
}

bool isGameOver(char matrix[ROW][COLUMN], unsigned int row, unsigned int col, char turn){
    
}

int main(){
    char board[ROW][COLUMN];
    initBoard(board);
    printBoard(board);
    bool gameOver = false;
    char turn = 'X';
    char input;
    unsigned int row, col;
    cout << "I want to play a game with you: \n";
    while(!gameOver){
        cout << "It's " << turn << " turn: \n";
        cin >> input;
        system("clear");
        if(setBoardCell(board, input, turn, &row, &col)){
            turn = (turn =='X') ? 'O' : 'X';   
            cout << row << col << endl;
            gameOver = checkIfGameOver(board);
        }else{
            cout << "Inserted value was invalid \n";
        }
        printBoard(board);
    }
    return 0;
}