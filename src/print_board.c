#include "print_board.h"
#include <stdio.h>

void printBoard(char board[LINE][LINE])
{
    for (int i = 0; i < LINE; i++) {
        printf("%d ", LINE - i);
        for (int j = 0; j < LINE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (int i = 'a'; i <= 'h'; i++) {
        printf("%c ", i);
    }
    printf("\n");
}
