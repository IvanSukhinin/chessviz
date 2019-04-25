.PHONY: all clean install uninstall
CC = gcc
CFLAGS = -Wall -Werror
CHESS := ./bin/chess
TEST := ./bin/test
INSTALL_PATH := /usr/local/bin
BUILD_SRC_DIR := ./build/src
BUILD_TEST_DIR := ./build/test

all: $(CHESS)

$(CHESS): $(BUILD_SRC_DIR)/main.o $(BUILD_SRC_DIR)/chess.o $(BUILD_SRC_DIR)/board.o $(BUILD_SRC_DIR)/print_board.o
	$(CC) $(BUILD_SRC_DIR)/main.o $(BUILD_SRC_DIR)/chess.o $(BUILD_SRC_DIR)/board.o $(BUILD_SRC_DIR)/print_board.o -o $(CHESS)

$(BUILD_SRC_DIR)/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o $(BUILD_SRC_DIR)/main.o

$(BUILD_SRC_DIR)/chess.o: src/chess.c
	$(CC) $(CFLAGS) -c src/chess.c -o $(BUILD_SRC_DIR)/chess.o

$(BUILD_SRC_DIR)/board.o: src/board.c
	$(CC) $(CFLAGS) -c src/board.c -o $(BUILD_SRC_DIR)/board.o

$(BUILD_SRC_DIR)/print_board.o: src/print_board.c
	$(CC) $(CFLAGS) -c src/print_board.c -o $(BUILD_SRC_DIR)/print_board.o

test: $(TEST)

$(TEST): $(BUILD_TEST_DIR)/main.o $(BUILD_TEST_DIR)/print_board.o $(BUILD_TEST_DIR)/board.o $(BUILD_TEST_DIR)/chess.o
	gcc  $(BUILD_TEST_DIR)/main.o $(BUILD_TEST_DIR)/print_board.o $(BUILD_TEST_DIR)/board.o $(BUILD_TEST_DIR)/chess.o -o $(TEST)

$(BUILD_TEST_DIR)/main.o: test/main.c 
	$(CC) $(CFLAGS) -c -I thirdparty -I src test/main.c -o $(BUILD_TEST_DIR)/main.o

$(BUILD_TEST_DIR)/chess.o: src/chess.c src/chess.h src/board.h src/print_board.h src/const.h 
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/chess.c -o $(BUILD_TEST_DIR)/chess.o

$(BUILD_TEST_DIR)/board.o: src/board.c src/board.h src/const.h
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/board.c -o $(BUILD_TEST_DIR)/board.o

$(BUILD_TEST_DIR)/print_board.o: src/print_board.c src/print_board.h src/const.h
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/print_board.c -o $(BUILD_TEST_DIR)/print_board.o

clean:
	rm -rf $(BUILD_SRC_DIR)/*.o $(BUILD_TEST_DIR)/*.o bin/chess bin/test

install: 
	install bin/chess $(INSTALL_PATH)

uninstall:
	rm -rf $(INSTALL_PATH)/chess