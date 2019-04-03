#include "chess.h"
#include "board.h"
#include "print_board.h"
#include <stdio.h>
#include <ctype.h>

int runChess(char board[LINE][LINE], char* cmd)
{
    int currentIndex = 0;
    while (isspace(cmd[currentIndex]) != 0) {
        currentIndex++;
    }
    currentIndex = checkNumeration(cmd, currentIndex);
    if (currentIndex == -1) {
        printf("Ошибка в нумерации : %s\n", cmd);
        return -1;
    }
    while (isspace(cmd[currentIndex]) != 0) {
        currentIndex++;
    }
    int commandIndex = currentIndex;
    int player = 0;
    while (player < PLAYER_COUNT) {
        char moveCommandFirst[LEN_MOVE_CMD];
        int commandWriteIndex = 0;
        while (isspace(cmd[commandIndex]) == 0) {
            if (commandIndex - currentIndex > 7) {
                printf("Ошибка в написании хода : %s\n", cmd);
                return -1;
            }
            moveCommandFirst[commandWriteIndex] = cmd[commandIndex];
            commandIndex++;
            commandWriteIndex++;
        }
        if (moveCommandFirst[0] == '\0') {
            return 0;
        }
        printf("-----%s-----\n", moveCommandFirst);
        moveCommandFirst[commandWriteIndex + 1] = '\0';
        if (checkFigureType(moveCommandFirst) == -1) {
            printf("Неизвестный тип фигуры %s\n", cmd);
            return -1;
        }
        if (checkFigureMove(board, moveCommandFirst) == -1) {
            return -1;
        }
        printBoard(board);
        while (isspace(cmd[commandIndex]) != 0) {
            commandIndex++;
        }
        currentIndex = commandIndex;
        player++;
    }
    return 0;
}
