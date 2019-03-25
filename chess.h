#define LINE 8
#define LEN_CMD 20

int checkNumbering(char* cmd);
int Swap(char board[LINE][LINE], char* cmd, char figureType);
void printBoard(char board[LINE][LINE]);
int checkBoard(char* cmd, int index);
char getFigureType(char board[LINE][LINE], char* cmd);
int checkFigure(char* cmd, int index);
int Chess(char board[LINE][LINE], char* cmd);