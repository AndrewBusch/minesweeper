/* basic back end for minesweeper */

#include "time.h"
#include "stdlib.h"
#include "stdio.h"

#define rowSize 10
#define columnSize 10
#define numMines 5

typedef struct{
	char value;

	int row;
	int column;
} square;

void printBoard( char **board );

main() {

	srand(time(NULL));

	/*
	 * 'b' = bomb
	 * '1' through '8' = count of adjacent bombs
	 * 'e' = empty and unchecked
	 * 'a' = activated during edge search
	 */
	char **board;

	//board = malloc((char**) );

	// fill out the minesweeper board
	int i,j; // iterators
	for(i = 0; i < rowSize; i++) {
		for(j = 0; j < columnSize; j++) {
			board[i][j] = 'e';
		}
	}

	// place mines on board
	int r, c;
	for(i=0; i<numMines; i++) {
		r = rand()%rowSize;
		c = rand()%columnSize;

		printf("mine at row %d, column %d\n", r, c);
		// if the space is filled,
		// subtract 1 to correct for number of mines placed
		if(board [r][c] == 'b') i--;

		board[r][c] = 'b';
	}

	printBoard(board);

	// fill out adjacent mine values

	printf("program ended correctly\n");
}

void printBoard( char **board ){
	int i, j;
	for(i = 0; i < rowSize; i++) {
		for(j = 0; j < columnSize; j++) {
			printf("[%c] ", board[i][j]);
		}
		printf("\n");
	}
}
