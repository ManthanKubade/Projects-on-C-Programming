#include <stdio.h>

char board[3][3];
char player = 'X';

void initializeBoard() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = ' ';
}

void displayBoard() {
    printf("\n");
    for(int i=0;i<3;i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if(i<2) printf("---|---|---\n");
    }
}

int checkWin() {
    for(int i=0;i<3;i++) {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player) return 1;
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player) return 1;
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player) return 1;
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player) return 1;
    return 0;
}

int main() {
    int row, col, moves=0;
    initializeBoard();

    while(1) {
        displayBoard();
        printf("Player %c enter row and column (0-2): ", player);
        scanf("%d %d", &row, &col);

        if(board[row][col]==' ') {
            board[row][col] = player;
            moves++;

            if(checkWin()) {
                displayBoard();
                printf("Player %c wins!\n", player);
                break;
            }

            if(moves==9) {
                displayBoard();
                printf("Game Draw!\n");
                break;
            }

            player = (player=='X') ? 'O' : 'X';
        } else {
            printf("Invalid move!\n");
        }
    }
    return 0;
}
