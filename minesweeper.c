/* basic back end for minesweeper */

#include "time.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct{
	char value;

	int row;
	int column;
} square;

void printBoard( char board[10][10] );

main() {

	srand(time(NULL));


	// minesweeper board
	int rowSize = 10;
	int columnSize = 10;
	int numMines = 5;

	int i,j; // iterators

	/*
	 * 'b' = bomb
	 * '1' through '8' = count of adjacent bombs
	 * 'e' = empty and unchecked
	 * 'a' = activated during edge search
	 */
	char board[rowSize][columnSize];

	// fill out the minesweeper board
	for(i = 0; i < rowSize; i++) {
		for(j = 0; j < columnSize; j++) {
			board[i][j] = 'e';
		}
	}

	//place mines on board
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

	printf("program ended correctly\n");
}

void printBoard( char board[10][10] ){
	int i, j;
	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			printf("[%c] ", board[i][j]);
		}
		printf("\n");
	}
}
