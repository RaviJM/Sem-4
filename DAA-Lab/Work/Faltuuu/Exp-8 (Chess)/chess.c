#include <stdio.h>
#include <stdbool.h>
#define n 4
int ChessBoard[n][n];


//function to print the Chess Board
//(prints 0 at empty places, prints 1 at places where Queens are present)
void printChessBoard(int ChessBoard[n][n]){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ",ChessBoard[i][j]);
        }
        printf("\n");
    }
}




//function to check if the Queen that we are going to place at [row,col] (not yet placed) is safe to place or not
//since we are placing the Queens column by column, starting from the 0th column, so
//before we place a new Queen on the chess board, we have to check at 3 line of sight of the current Queen position to check for any attacking Queens that might be already placed:
//          - at the Left side of the Queen
//          - Top Left diagonal
//          - Bottom Left diagonal

//This function is called when there are already 'col' Queens placed in columns 0 to (col-1)
bool isSafe(int ChessBoard[n][n], int row, int col){
    int i,j;

    //check on Left side
    for (i=0;i<col;i++){
        if (ChessBoard[row][i]){
            return false;   //if any Queen is present on the left side
        }
    }

    //check on Top Left diagonal
    for (i=row,j=col ; (i>=0 && j>=0) ; i--,j--){
        if (ChessBoard[i][j]){
            return false;
        }
    }

    //check on Bottom Left diagonal
    for (i=row,j=col ; i<n && j>=0 ; i++,j--){
        if (ChessBoard[i][j]){
            return false;
        }
    }

    //if no attacking Queen is found in all 3 cases
    return true;
}




//function that is called recursively to solve the NQueens problem, using Backtracking
bool solve(int ChessBoard[n][n], int col){

    //base case (if all thet Queens are placed)
    if (col >= n){
        return true;
    }

    //else consider the given col and try placing the queen one by one in each row of that column
    for (int i=0;i<n;i++){
        //now check if the queen can be placed at this position or not. i.e. at (i,col)
        if (isSafe(ChessBoard, i, col)){
            //place the Queen at that spot
            ChessBoard[i][col] = 1;

            //use recursion for placing other Queens
            if (solve(ChessBoard, col + 1)){
                return true;
            }

            //if placing the Queen at that spot (i,col) doesn't lead to a solution,
            // or simply if we can't place the Queen there,
            // then, remove the Queen from position (i,col)
            // BACKTRACK

            ChessBoard[i][col] = 0;
        }
    }
    //if Queen cannot be placed in any row of the column col, then return false
    return false;
}




int main(){

    int ChessBoard[n][n];
    //making chess board(initialize with all 0s)
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            ChessBoard[i][j] = 0;
        }
    }

    if (solve(ChessBoard, 0)){
        printChessBoard(ChessBoard);
    }
    else printf("No solution exists for n = %d", n);
}