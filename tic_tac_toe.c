#include <stdio.h>

char board[3][3];
char currentPlayer = 'X';

void initializeBoard() {
    char ch = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

void displayBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i != 2)
            printf("\n---|---|---\n");
    }
    printf("\n");
}

int checkWinner() {

    // Rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return 1;
    }

    // Columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            return 1;
    }

    // Diagonals
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return 1;

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return 1;

    return 0;
}

int isBoardFull() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;
}

void makeMove() {

    int choice;

    printf("\nPlayer %c, Enter Position (1-9): ", currentPlayer);
    scanf("%d", &choice);

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(choice < 1 || choice > 9 ||
       board[row][col] == 'X' ||
       board[row][col] == 'O') {

        printf("Invalid Move! Try Again.\n");
        makeMove();
        return;
    }

    board[row][col] = currentPlayer;
}

void switchPlayer() {
    if(currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main() {

    initializeBoard();

    while(1) {

        displayBoard();

        makeMove();

        if(checkWinner()) {
            displayBoard();
            printf("\n🎉 Player %c Wins!\n", currentPlayer);
            break;
        }

        if(isBoardFull()) {
            displayBoard();
            printf("\nMatch Draw!\n");
            break;
        }

        switchPlayer();
    }

    return 0;
}