#pragma once

#include "const.h"

#define PLAYER_COUNT 2

enum commandIndex {
    figureLocationLetter,
    figureLocationIndex,
    moveOperation,
    figureDestinationLetter,
    figureDestinationIndex,
};

typedef struct {
    int figureLocationX;
    int figureLocationY;
} locationCoordinates;

typedef struct {
    int figureDestinationX;
    int figureDestinationY;
} destinationCoordinates;

char getFigureType(char board[LINE][LINE], char* cmd);
void makeMove(
        char board[LINE][LINE],
        char* cmd,
        locationCoordinates l,
        destinationCoordinates d);
int checkMoveErrors(
        char board[LINE][LINE],
        char* cmd,
        char figureType,
        locationCoordinates l,
        destinationCoordinates d);
locationCoordinates getLocationCoordinates(char* cmd);
destinationCoordinates getDestinationCoordinates(char* cmd);
int checkRange(char* cmd);
int checkFigureMove(char board[LINE][LINE], char* cmd);
int checkFigureType(char* cmd);
int checkNumeration(char* cmd, int currentIndex);