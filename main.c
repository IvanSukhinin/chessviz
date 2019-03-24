#include <stdio.h>
#define LINE 8

int main()
{
    printf("-------------CHESS---------------\n\n");

    char board[LINE][LINE] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                              {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                              {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

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

    return 0;
}