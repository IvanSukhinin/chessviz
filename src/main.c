#include "chess.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("-------------CHESS---------------\n\n");
    if (argv[1] == NULL) {
        printf("Введи main <filename>\n");
        return -1;
    }
    char board[LINE][LINE] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                              {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                              {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char cmd[LEN_CMD];
    FILE* userFile;
    userFile = fopen(argv[1], "r");
    if (!userFile) {
        printf("Не удалось открыть файл\n");
        return -1;
    }
    printBoard(board);
    while (!feof(userFile)) {
        fgets(cmd, LEN_CMD, userFile);
        if (runChess(board, cmd) == -1) {
            return -1;
        }
    }

    fclose(userFile);
    return 0;
}