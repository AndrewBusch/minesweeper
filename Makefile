all: MS

MS: list.o minesweeper.o
	gcc minesweeper.o list.o -o minesweeper

list.o: list.c list.h
	gcc -c list.c

minesweeper.o: minesweeper.c minesweeper.h list.h
	gcc -c minesweeper.c

clean:
	rm -f minesweeper.o
	rm -f minesweeper
	rm -f list.o
