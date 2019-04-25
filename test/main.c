#define CTEST_MAIN
#define CTEST_COLOR_OK

#include <board.h>
#include <chess.h>
#include <const.h>
#include <ctest.h>
#include <print_board.h>

#define CMD_MOVE "e2-e4"
#define CMD_NUM "1."
#define CMD_CAPACITY 10

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
