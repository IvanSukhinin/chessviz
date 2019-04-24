#include "board.h"
#include <ctype.h>
#include <stdio.h>

int checkFigureMove(char board[LINE][LINE], char* cmd)
{
    /*Получаем тип фигуры*/
    char figureType = getFigureType(board, cmd);
    /*Проверяем диапазон*/
    int range = checkRange(cmd);
    if (range == -1) {
        return -1;
    }

    /* Получаем координаты */
    locationCoordinates l;
    destinationCoordinates d;
    l = getLocationCoordinates(cmd);
    d = getDestinationCoordinates(cmd);

    /*Проверки на normal*/
    int checkMoveError = checkMoveErrors(board, cmd, figureType, l, d);
    if (checkMoveError == -1) {
        return -1;
    }

    /* Делаем ход */
    makeMove(board, cmd, l, d);

    return 0;
}

char getFigureType(char board[LINE][LINE], char* cmd)
{
    /* Получаем тип фигуры (1-ый символ в строке) */
    if (cmd[0] >= 'a' && cmd[0] <= 'h') {
        locationCoordinates l;
        l = getLocationCoordinates(cmd);
        if (board[l.figureLocationX][l.figureLocationY] == 'P') {
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

    return figureType;
}

void makeMove(
        char board[LINE][LINE],
        char* cmd,
        locationCoordinates l,
        destinationCoordinates d)
{
    /* Передвигаем фигуру */
    char temp = board[l.figureLocationX][l.figureLocationY];
    board[l.figureLocationX][l.figureLocationY] = '.';
    board[d.figureDestinationX][d.figureDestinationY] = temp;
}

int checkRange(char* cmd)
{
    /* Проверка на выход за пределы поля */
    if (!((cmd[figureLocationLetter] >= 'a' && cmd[figureLocationLetter] <= 'h')
          && (cmd[figureLocationIndex] >= '1'
              && cmd[figureLocationIndex] <= '8')
          && (cmd[figureDestinationIndex] >= '0'
              && cmd[figureDestinationIndex] <= '8')
          && (cmd[figureDestinationLetter] >= 'a'
              && cmd[figureDestinationLetter] <= 'h'))
        || (cmd[figureDestinationIndex + 1] > '0'
            && cmd[figureDestinationIndex + 1] < '9')
        || (cmd[figureLocationIndex + 1] > '0'
            && cmd[figureLocationIndex + 1] < '9')) {
        printf("Выход за пределы поля : %s\n", cmd);
        return -1;
    }

    return 0;
}

int checkMoveErrors(
        char board[LINE][LINE],
        char* cmd,
        char figureType,
        locationCoordinates l,
        destinationCoordinates d)
{
    /*Проверки на Normal*/
    if (cmd[moveOperation] != '-' && cmd[moveOperation] != 'x') {
        printf("%s\nНеизвестная операция : %c\n", cmd, cmd[moveOperation]);
        return -1;
    }
    if (cmd[moveOperation] == 'x'
        && board[d.figureDestinationX][d.figureDestinationY] == '.') {
        printf("Ошибка. Нет фигуры для взятия : %s\n", cmd);
        return -1;
    }
    if (cmd[moveOperation] == '-'
        && board[d.figureDestinationX][d.figureDestinationY] != '.') {
        printf("Ошибка. Клетка не пустая : %s\n", cmd);
        return -1;
    }
    if (toupper(figureType)
        != toupper(board[l.figureLocationX][l.figureLocationY])) {
        printf("Обозначения фигур должны соответствовать фактическим : %s\n",
               cmd);
        return -1;
    }

    return 0;
}

locationCoordinates getLocationCoordinates(char* cmd)
{
    /*Где находится фигура*/
    locationCoordinates l;
    l.figureLocationX = ('8' - cmd[figureLocationIndex]);
    l.figureLocationY = ('a' - cmd[figureLocationLetter]) * -1;
    return l;
}

destinationCoordinates getDestinationCoordinates(char* cmd)
{
    /*Пункт назначения*/
    destinationCoordinates d;
    d.figureDestinationX = ('8' - cmd[figureDestinationIndex]);
    d.figureDestinationY = ('a' - cmd[figureDestinationLetter]) * -1;
    return d;
}

int checkFigureType(char* cmd)
{
    /*Проверка на тип фигуры*/
    int figureIndex = 0;
    if (!(cmd[figureIndex] == 'K' || cmd[figureIndex] == 'Q'
          || cmd[figureIndex] == 'R' || cmd[figureIndex] == 'B'
          || cmd[figureIndex] == 'N'
          || (cmd[figureIndex] >= 'a' && cmd[figureIndex] <= 'h'))) {
        return -1;
    }

    return 0;
}

int checkNumeration(char* cmd, int currentIndex)
{
    /* Проверка нумерации ходов */
    int numerationIndex;
    for (numerationIndex = currentIndex; cmd[numerationIndex] != '.';
         numerationIndex++) {
        if (cmd[numerationIndex] < '1' || cmd[numerationIndex] > '8') {
            return -1;
        }
        if (cmd[numerationIndex] == '\0') {
            return -1;
        }
    }
    /* Выводим номер хода */
    for (int i = currentIndex; cmd[i] != '.'; i++) {
        printf("%c", cmd[i]);
    }
    printf(" ход : \n");

    return numerationIndex + 1;
}
