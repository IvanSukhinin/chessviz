#pragma once

#include "const.h"

#define PLAYER_COUNT 2

char getFigureType(char board[LINE][LINE], char* cmd);
void swap(char board[LINE][LINE], char* cmd);
int checkRange(char* cmd);
int checkNumeration(char* cmd, int currentIndex);
int checkFigureMove(char board[LINE][LINE], char* cmd);
int checkFigureType(char* cmd);
