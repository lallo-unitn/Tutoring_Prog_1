#include <stdio.h>
#include <stdlib.h>

#define ROW 7
#define COLUMN 7

#define TRUE 1
#define FALSE 0

int isBoardFrame(char test);
void initBoard(char matrix[ROW][COLUMN]);
void printBoard(char matrix[ROW][COLUMN]);
int setBoardCell(char matrix[ROW][COLUMN], char input, char turn, unsigned int *row, unsigned int *col);
int isGameOver(char matrix[ROW][COLUMN], unsigned int row, unsigned int col, char turn);

int main(){
    char board[ROW][COLUMN];
    initBoard(board);
    printBoard(board);
    int gameOver = FALSE;
    char turn = 'X';
    char input;
    unsigned int row, col;
    printf("I want to play a game with you: \n");
    while (!gameOver)
    {
        printf("It's %c turn: \n", turn);
        scanf("%c", &input);
        system("clear");
        if(setBoardCell(board, input, turn, &row, &col)){  
            //cout << row << col << endl;
            gameOver = isGameOver(board, row, col, turn);
            turn = (turn =='X') ? 'O' : 'X'; 
        }else{
            printf("Inserted value was invalid \n");
        }
        printBoard(board);
    }
    return 0;
}

int isBoardFrame(char test){
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
                slotNumber++;
            }
        }   
    }
}

void printBoard(char matrix[ROW][COLUMN]){
    for (unsigned int i = 0; i < COLUMN; i++)
    {
        for (unsigned int j = 0; j < ROW; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

int setBoardCell(char matrix[ROW][COLUMN], char input, char turn, unsigned int *row, unsigned int *col){
    int isInputValid = FALSE;
    if(input < '1' || input > '9') return isInputValid;
    for (unsigned int i = 0; i < ROW; i++)
    {
        for (unsigned int j = 0; j < COLUMN; j++)
        {
            if(matrix[i][j] == input){
                matrix[i][j] = turn;
                isInputValid = TRUE;
                *row = i;
                *col = j;
            }
        }   
    }
    return isInputValid;
}

int isGameOver(char matrix[ROW][COLUMN], unsigned int row, unsigned int col, char turn){
    int gameOver = TRUE;

    //CHECK SAME ROW
    for (unsigned int i = 0; i < COLUMN; i++)
    {
        if(
                matrix[row][i] != turn &&
                !isBoardFrame(matrix[row][i])
            ){
            gameOver = FALSE;
        }
    }
    if(gameOver) return TRUE;

    gameOver = TRUE;

    //CHECK SAME COLUMN
    for (unsigned int i = 0; i < ROW; i++)
    {
        if(
                matrix[i][col] != turn &&
                !isBoardFrame(matrix[i][col])
            ){
            gameOver = FALSE;
        }
    }
    if(gameOver) return TRUE;

    gameOver = TRUE;

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
                gameOver = FALSE;
            }
            currRow++;
            currCol++;
        }
        if(gameOver) return TRUE;
    }

    gameOver = TRUE;
    
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
                gameOver = FALSE;
            }
            currRow++;
            currCol--;
        }
        if(gameOver) return TRUE;
    }
    return FALSE;
}