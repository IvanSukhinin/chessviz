#define CTEST_MAIN
#define CTEST_COLOR_OK

#include <board.h>
#include <print_board.h>
#include <chess.h>
#include <const.h>
#include <ctest.h>

#define CMD_MOVE "e2-e4"
#define CMD_CAPACITY 10

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(input_test, check_figure_type) {
    // Given
    char turn[CMD_CAPACITY] = CMD_MOVE;

    // When
    const int result = checkFigureType(turn);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}