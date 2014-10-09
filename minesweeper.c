/**
  * basic back end for minesweeper
  */

//#include "minesweeper.h"
#include "time.h"
#include "stdlib.h"
#include "stdio.h"

#define rowSize 10
#define columnSize 10
#define numMines 20

void printBoard( char (*board)[columnSize] );
void placeMines( char (*board)[columnSize] );
void wipeBoard( char (*board)[columnSize] );
void fillNumberValues( char (*board)[columnSize] );

main() {

	srand(time(NULL));

	/*
	 * 'b' = bomb
	 * '0' through '8' = count of adjacent bombs
	 * 'e' = empty and unchecked
	 * 'a' = activated during edge search
	 */
	char (*board)[columnSize] = malloc((sizeof *board) * rowSize);

	wipeBoard(board); // fill out the minesweeper board
	placeMines(board); // place mines on board
	fillNumberValues(board);// fill adjacent mine values for inner board
	printBoard(board); // view board

	printf("program ended correctly\n");
}

/**
  * print out current state of board
  */
void printBoard( char (*board)[columnSize] ) {
	printf("current board:\n");
	int i, j;
	for(i = 0; i < rowSize; i++) {
		for(j = 0; j < columnSize; j++) {
			printf("[%c]", board[i][j]);
		}
		printf("\n");
	}
}

/**
  * fill the board with randomly placed mines depending on the mine count
  */
void placeMines( char (*board)[columnSize] ) {
	int r, c, i, j;
	for(i=0; i<numMines; i++) {
		r = rand()%rowSize;
		c = rand()%columnSize;

		printf("mine at row %d, column %d\n", r, c);
		// if the space is filled,
		// subtract 1 to correct for number of mines placed
		if(board [r][c] == 'b') i--;

		board[r][c] = 'b';
	}
}

/**
  * reset the board by filling all squares with 'e'
  */
void wipeBoard( char (*board)[columnSize] ) {
	int i,j;
	for(i = 0; i < rowSize; i++) {
		for(j = 0; j < columnSize; j++) {
			board[i][j] = 'e';
		}
	}
}

/**
  * fill the inside of the board with values based on adjacent bombs
  */
void fillInnerValues( char (*board)[columnSize] ) {
	int i, j, k, l;
	int count;
	for(i = 1; i < rowSize-1; i++) {
		for(j = 1; j < columnSize-1; j++) {
			if( board[i][j] == 'e' ) {
				count = 0;
				if( board[i-1][j-1] == 'b' ) count++;
				if( board[i][j-1]   == 'b' ) count++;
				if( board[i+1][j-1] == 'b' ) count++;
				if( board[i-1][j]   == 'b' ) count++;
				if( board[i+1][j]   == 'b' ) count++;
				if( board[i-1][j+1] == 'b' ) count++;
				if( board[i][j+1]   == 'b' ) count++;
				if( board[i+1][j+1] == 'b' ) count++;
				board[i][j] = (char) (((int) '0') + count);
			}
		}
	}
}
