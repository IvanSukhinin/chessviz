.PHONY: all clean install uninstall
CC = gcc
CFLAGS = -Wall -Werror

all: bin/chess

bin/chess: build/main.o build/chess.o build/board.o build/print_board.o
	$(CC) build/main.o build/chess.o build/board.o build/print_board.o -o bin/chess

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/chess.o: src/chess.c
	$(CC) $(CFLAGS) -c src/chess.c -o build/chess.o

build/board.o: src/board.c
	$(CC) $(CFLAGS) -c src/board.c -o build/board.o

build/print_board.o: src/print_board.c
	$(CC) $(CFLAGS) -c src/print_board.c -o build/print_board.o

install: 
	install bin/chess /usr/local/bin

uninstall:
	rm -rf /usr/local/bin/chess

clean:
	rm -rf build/*.o bin/chess
