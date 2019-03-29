#pragma once

#define LINE 8
#define LEN_CMD 100
#define LEN_MOVE_CMD 20
#define PLAYER_COUNT 2

int checkFigureType(char* cmd);
int checkFigureMove(char board[LINE][LINE], char* cmd);
int checkNumeration(char* cmd, int currentIndex);
void printBoard(char board[LINE][LINE]);
void Swap(char board[LINE][LINE], char* cmd);
char getFigureType(char board[LINE][LINE], char* cmd);
int runChess(char board[LINE][LINE], char* cmd);
