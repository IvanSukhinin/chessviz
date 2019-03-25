#include "chess.h"
#include <ctype.h>
#include <stdio.h>

int Chess(char board[LINE][LINE], char* cmd)
{
    if (checkNumbering(cmd) == -1) {
        printf("%s\n", cmd);
        return 0;
    }
    int size;
    for (size = 0; cmd[size] != '\0'; size++) {
    }
    if (size > 7) {
        printf("%s\nОшибка в синтаксисе команды\n", cmd);
        return -1;
    }
    int index = 0;
    char figureType = getFigureType(board, cmd);
    while (index < 4) {
        // Проверка на тип фигуры
        if (checkFigure(cmd, index) == -1) {
            printf("%s\ncheckFigure == -1\n", cmd);
            return -1;
        }
        // Проверка диапазона
        if (checkBoard(cmd, index) == -1) {
            printf("%s\ncheckBoard == -1\n", cmd);
            return -1;
        }
        index += 3;
    }
    printf("------%s------\n", cmd);
    if (Swap(board, cmd, figureType) == -1) {
        return -1;
    }
    printBoard(board);

    return 0;
}

int checkNumbering(char* cmd)
{
    // Проверка нумерации ходов
    if (cmd[0] >= '1' && cmd[0] <= '9') {
        return -1;
    }
    return 0;
}

int checkFigure(char* cmd, int index)
{
    // Проверка на тип фигуры
    if (!(cmd[index] == 'K' || cmd[index] == 'Q' || cmd[index] == 'R'
          || cmd[index] == 'B' || cmd[index] == 'N'
          || (cmd[index] >= 'a' && cmd[index] <= 'h'))) {
        return -1;
    }
    return 0;
}

char getFigureType(char board[LINE][LINE], char* cmd)
{
    // Удаляет первый элемент из cmd
    if (cmd[0] >= 'a' && cmd[0] <= 'h') {
        int figure_location_x = ('8' - cmd[1]);
        int figure_location_y = ('a' - cmd[0]) * -1;
        if (board[figure_location_x][figure_location_y] == 'P') {
            return 'P';
        } else {
            return 'p';
        }
    }
    int i;
    char figureType = cmd[0];
    for (i = 0; cmd[i] != '\0'; i++) {
        cmd[i] = cmd[i + 1];
    }
    cmd[i + 1] = ' ';
    // И возвращает тип фигуры
    return figureType;
}

int checkBoard(char* cmd, int index)
{
    // Проверка на выход за пределы поля
    if ((cmd[index] >= 'a' && cmd[index] <= 'h')
        && (cmd[index + 1] >= '1' && cmd[index + 1] <= '8')
        && (cmd[index + 2] < '0' || cmd[index + 2] > '9')) {
        return 0;
    }
    return -1;
}

int Swap(char board[LINE][LINE], char* cmd, char figureType)
{
    // Передвигаем фигуру
    int figure_location_x = ('8' - cmd[1]);
    int figure_location_y = ('a' - cmd[0]) * -1;
    int figure_destination_x = ('8' - cmd[4]);
    int figure_destination_y = ('a' - cmd[3]) * -1;
    if (toupper(figureType)
        != toupper(board[figure_location_x][figure_location_y])) {
        printf("Обозначения фигур должны соответствовать фактическим.\n");
        return -1;
    }
    if (cmd[2] == 'x'
        && board[figure_destination_x][figure_destination_y] == '.') {
        printf("Ошибка. Нет фигуры для взятия.\n");
        return -1;
    }
    if (cmd[2] == '-'
        && board[figure_destination_x][figure_destination_y] != '.') {
        printf("Ошибка. Клетка не пустая.\n");
        return -1;
    }

    char temp = board[figure_location_x][figure_location_y];
    board[figure_location_x][figure_location_y] = '.';
    board[figure_destination_x][figure_destination_y] = temp;

    return 0;
}

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