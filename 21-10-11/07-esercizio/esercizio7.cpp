#include <cstdio>
#include <iostream>
using namespace std;

#define ROW 7
#define COLUMN 7

bool isBoardFrame(char test);
void initBoard(char matrix[ROW][COLUMN]);
void printBoard(char matrix[ROW][COLUMN]);
bool setBoardCell(char matrix[ROW][COLUMN], char input, char turn, unsigned int *row, unsigned int *col);
bool isGameOver(char matrix[ROW][COLUMN], unsigned int row, unsigned int col, char turn);

int main(){
    char board[ROW][COLUMN];
    initBoard(board);
    printBoard(board);
    bool gameOver = false;
    char turn = 'X';
    char input;
    unsigned int row, col;
    cout << "I want to play a game with you: \n";
    while (!gameOver)
    {
        cout << "It's " << turn << " turn: \n";
        cin >> input;
        system("clear");
        if(setBoardCell(board, input, turn, &row, &col)){  
            //cout << row << col << endl;
            gameOver = isGameOver(board, row, col, turn);
            turn = (turn =='X') ? 'O' : 'X'; 
        }else{
            cout << "Inserted value was invalid \n";
        }
        printBoard(board);
    }
    return 0;
}

bool isBoardFrame(char test){
    return test == '-' || test == '|';
}

void initBoard(char matrix[ROW][COLUMN]){
    char slotNumber = '1';
    for (unsigned int currRow = 0; currRow < ROW; currRow++)
    {
        for (unsigned int currCol = 0; currCol < COLUMN; currCol++)
        {
            if(currRow%2 == 0){
                matrix[currRow][currCol] = '-';
            }else if(currCol%2 == 0){
                matrix[currRow][currCol] = '|';
            }else{
                matrix[currRow][currCol] = slotNumber;
                cout << slotNumber << ": " << currRow << " " << currCol << endl;
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
            cout << matrix[i][j];
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
                cout << "SET: " << i << " " << j << endl;
                *row = i;
                *col = j;
            }
        }   
    }
    return isInputValid;
}

bool isGameOver(char matrix[ROW][COLUMN], unsigned int row, unsigned int col, char turn){
    bool gameOver = true;

    //CHECK SAME ROW
    for (unsigned int i = 0; i < COLUMN; i++)
    {
        if(
                matrix[row][i] != turn &&
                !isBoardFrame(matrix[row][i])
            ){
                cout << row << " " << i << endl;
            gameOver = false;
        }
    }
    if(gameOver) return true;
    cout << "Passed isGameOverRow" << endl;

    gameOver = true;

    //CHECK SAME COLUMN
    for (unsigned int i = 0; i < ROW; i++)
    {
        if(
                matrix[i][col] != turn &&
                !isBoardFrame(matrix[i][col])
            ){
            cout << i << " " << col << endl;
            gameOver = false;
        }
    }
    if(gameOver) return true;
    cout << "Passed isGameOverCol" << endl;

    gameOver = true;

    //CHECK FIRST DIAGONAL

    int currRow = row;
    int currCol = col;
    if(row == col){
        while (currCol > 0 && currRow > 0)
        {
            currCol--;
            currRow--;
        }
        while (currRow < ROW && currCol < COLUMN && gameOver)
        {
            if( 
                    matrix[currRow][currCol] != turn &&
                    !isBoardFrame(matrix[currRow][currCol])
                ){
                cout << row << " " << col << endl;
                gameOver = false;
            }
            currRow++;
            currCol++;
        }
        if(gameOver) return true;
        cout << "Passed isGameOverDia1" << endl;
    }

    gameOver = true;
    
    //CHECK SECOND DIAGONAL
    if(col == COLUMN-1-row){
        currRow = row;
        currCol = col;
        while (currCol < COLUMN && currRow > 0)
        {
            currCol++;
            currRow--;
        } 
        while (currRow < ROW && currCol >= 0 && gameOver)
        {
            if( 
                    matrix[currRow][currCol] != turn &&
                    !isBoardFrame(matrix[currRow][currCol])
                ){
                cout << currRow << " " << currCol << endl;
                gameOver = false;
            }
            currRow++;
            currCol--;
        }
        if(gameOver) return true;
        cout << "Passed isGameOverDia2" << endl;
    }
    return false;
}