#define CTEST_MAIN
#define CTEST_COLOR_OK

#include <board.h>
#include <chess.h>
#include <const.h>
#include <ctest.h>
#include <print_board.h>

#define CMD_MOVE "e2-e4"
#define CMD_MOVE_ERR "r22*y53"
#define CMD_NUM_ERR "2e."
#define CMD_NUM "1."
#define CMD_CAPACITY 10

char board[LINE][LINE] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                          {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                          {'.', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', '.', '.', '.', '.', '.'},
                          {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                          {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
// CHECK INPUT CMD
CTEST(input_test, check_figure_type)
{
    // Given
    char cmd[CMD_CAPACITY] = CMD_MOVE;

    // When
    const int result = checkFigureType(cmd);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input_test, check_figure_type_bad_input)
{
    // Given
    char cmd[CMD_CAPACITY] = CMD_MOVE_ERR;

    // When
    const int result = checkFigureType(cmd);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(input_test, check_numeration)
{
    // Given
    char cmd[CMD_CAPACITY] = CMD_NUM;

    // When
    const int result = checkNumeration(cmd, 0);

    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(input_test, check_numeration_bad_input)
{
    // Given
    char cmd[CMD_CAPACITY] = CMD_NUM_ERR;

    // When
    const int result = checkNumeration(cmd, 0);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

// CHECK FIGURE MOVE
CTEST(move_test, check_get_figure_type)
{
    // Given
    char cmd[CMD_CAPACITY] = CMD_MOVE;

    // When
    const int result = getFigureType(board, cmd);

    // Then
    const int expected = 'P';
    ASSERT_EQUAL(expected, result);
}

CTEST(move_test, check_range)
{
    // Given
    char cmd[CMD_CAPACITY] = CMD_MOVE;

    // When
    const int result = checkRange(cmd);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move_test, check_range_bad_input)
{
    // Given
    char cmd[CMD_CAPACITY] = CMD_MOVE_ERR;

    // When
    const int result = checkRange(cmd);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(move_test, check_normal_level_move_errors)
{
    // Given
    char cmd[CMD_CAPACITY] = CMD_MOVE;
    locationCoordinates l;
    l.figureLocationX = 6;
    l.figureLocationY = 4;
    destinationCoordinates d;
    d.figureDestinationX = 4;
    d.figureDestinationY = 4;

    // When
    const int result = checkMoveErrors(board, cmd, 'P', l, d);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move_test, check_figure_move)
{
    // Given
    char cmd[CMD_CAPACITY] = CMD_MOVE;

    // When
    const int result = checkFigureMove(board, cmd);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move_test, check_figure_move_bad_input)
{
    // Given
    char cmd[CMD_CAPACITY] = CMD_MOVE_ERR;

    // When
    const int result = checkFigureMove(board, cmd);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}
