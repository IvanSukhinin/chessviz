#pragma once

#include "const.h"

#define PLAYER_COUNT 2

typedef struct {
	int figureLocationX;
	int figureLocationY;
} locationCoordinates;

typedef struct {
    int figureDestinationX;
    int figureDestinationY;
} destinationCoordinates;

char getFigureType(char board[LINE][LINE], char* cmd);
void swap(char board[LINE][LINE], char* cmd);
locationCoordinates getLocationCoordinates(char* cmd);
destinationCoordinates getDestinationCoordinates(char* cmd);
int checkRange(char* cmd);
int checkNumeration(char* cmd, int currentIndex);
int checkFigureMove(char board[LINE][LINE], char* cmd);
int checkFigureType(char* cmd);
