CC = gcc
CFLAGS = -Wall -Werror -c

all: main

main: main.o chess.o move-*.o
	$(CC) build/main.o build/chess.o -o bin/main

move-*.o: main.o chess.o
	mv *.o build/ 

main.o: src/main.c
	$(CC) $(CFLAGS) src/main.c

chess.o: src/chess.c
	$(CC) $(CFLAGS) src/chess.c 

clean:
	rm -rf build/*.o bin/main