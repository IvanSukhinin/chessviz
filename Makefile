.PHONY: clean
CC = gcc
CFLAGS = -Wall -Werror

All: bin/main

bin/main: build/main.o build/chess.o
	$(CC) build/main.o build/chess.o -o bin/main

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/chess.o: src/chess.c
	$(CC) $(CFLAGS) -c src/chess.c -o build/chess.o

clean:
	rm -rf build/*.o main