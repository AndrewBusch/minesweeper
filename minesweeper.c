/*
 * basic back end for minesweeper
 * Andrew Busch
 */

#include "minesweeper.h"
#include "list.h"

main() {
	srand( time(NULL));

	/*
	 * 'b' = bomb
	 * '0' through '8' = count of adjacent bombs
	 * 'e' = empty and unchecked
	 * 'a' = activated during edge search
	 * 's' = selected by user
	 */
	square (*board)[columnSize] = malloc( (sizeof *board)*rowSize);
	
	wipeBoard(board);	// zero out the minesweeper board
	placeMines(board);	// place mines on board
	fillValues(board);	// fill adjacent mine values for entire board
	printBoard(board);	// view board
	
}

/*
 * print out current state of board
 */
void printBoard( square (*board)[columnSize]) {
	printf("current board:\n");
	int i, j;
	for(i = 0; i < rowSize; i++) {
		for(j = 0; j < columnSize; j++) {
			printf("[%c]", board[i][j].status);
		}
		printf("\n");
	}
}

/*
 * fill the board with randomly placed mines depending on the mine count
 */
void placeMines( square (*board)[columnSize]) {
	int r, c, i;
	for(i=0; i<numMines; i++) {
		r = rand()%rowSize;
		c = rand()%columnSize;

		// if the space is filled,
		// subtract 1 to correct for number of mines placed
		if(board[r][c].status == 'b' || board[r][c].status == 's')
			i--;
		else
			board[r][c].status = 'b';
	}
}

/**
  * reset the board by filling all squares with 'e'
  */
void wipeBoard( square (*board)[columnSize]) {
	int i,j;
	for(i = 0; i < rowSize; i++) {
		for(j = 0; j < columnSize; j++) {
			board[i][j].row = i;
			board[i][j].column = j;
			board[i][j].status = 'e';
		}
	}
}

/**
  * fill the inside of the board with values based on adjacent bombs
  */
void fillValues( square (*board)[columnSize]) {
	int i, j;
	neighbor *list;
	for(i = 0; i < rowSize; i++) {
		for(j = 0; j < columnSize; j++) {
			if( board[i][j].status != 'b') {
				list = NULL;
				list = getNeighbors( board, i, j);
				board[i][j].status = (char) (((int) '0') + getBombCount(list));
			}
		}
	}
}

/*
 * return a linked list of the values of neighbors for a given point on the board
 */
neighbor* getNeighbors( square (*board)[columnSize], int row, int column) {

	neighbor *list = NULL;
	if( row < rowSize-1 && row > 0 && column < columnSize-1 && column > 0) {	// not on edge of board
		list = addNeighbor( list, board[row-1][column-1] );
		list = addNeighbor( list, board[row][column-1]   );
		list = addNeighbor( list, board[row+1][column-1] );
		list = addNeighbor( list, board[row-1][column]   );
		list = addNeighbor( list, board[row+1][column]   );
		list = addNeighbor( list, board[row-1][column+1] );
		list = addNeighbor( list, board[row][column+1]   );
		list = addNeighbor( list, board[row+1][column+1] );
		return list;
	}
	if( row == 0 && column < columnSize-1 && column > 0) { 		// top of board
		list = addNeighbor( list, board[row][column-1]   );
		list = addNeighbor( list, board[row+1][column-1] );
		list = addNeighbor( list, board[row+1][column]   );
		list = addNeighbor( list, board[row][column+1]   );
		list = addNeighbor( list, board[row+1][column+1] );
		return list;
	}
	if( row == rowSize-1 && column < columnSize-1 && column > 0) { 	// bottom edge of board
		list = addNeighbor( list, board[row-1][column-1] );
		list = addNeighbor( list, board[row][column-1]   );
		list = addNeighbor( list, board[row-1][column]   );
		list = addNeighbor( list, board[row-1][column+1] );
		list = addNeighbor( list, board[row][column+1]   );
		return list;
	}
	if( row < rowSize-1 && row > 0 && column == 0) { 		// left edge of board
		list = addNeighbor( list, board[row-1][column]   );
		list = addNeighbor( list, board[row+1][column]   );
		list = addNeighbor( list, board[row-1][column+1] );
		list = addNeighbor( list, board[row][column+1]   );
		list = addNeighbor( list, board[row+1][column+1] );
		return list;
	}
	if( row < rowSize-1 && row > 0 && column == columnSize-1) { 	// right edge of board
		list = addNeighbor( list, board[row-1][column-1] );
		list = addNeighbor( list, board[row][column-1]   );
		list = addNeighbor( list, board[row+1][column-1] );
		list = addNeighbor( list, board[row-1][column]   );
		list = addNeighbor( list, board[row+1][column]   );
		return list;
	}
	if( row == 0 && column == 0) { 					// top left corner of board
		list = addNeighbor( list, board[row+1][column]   );
		list = addNeighbor( list, board[row][column+1]   );
		list = addNeighbor( list, board[row+1][column+1] );
		return list;
	}
	if( row == rowSize-1 && column == 0) { 				// bottom left corner of board
		list = addNeighbor( list, board[row-1][column]   );
		list = addNeighbor( list, board[row][column+1]   );
		list = addNeighbor( list, board[row-1][column+1] );
		return list;
	}
	if( row == 0 && column == columnSize-1) { 			// top right corner of board
		list = addNeighbor( list, board[row+1][column]	);
		list = addNeighbor( list, board[row+1][column-1]);
		list = addNeighbor( list, board[row][column-1]	);
		return list;
	}
	if( row == rowSize-1 && column == columnSize-1) { 		// bottom right corner of board
		list = addNeighbor( list, board[row-1][column]	);
		list = addNeighbor( list, board[row-1][column-1]);
		list = addNeighbor( list, board[row][column-1]	);
		return list;
	}
	return list;
}

/*
 * takes a list of neighbors and returns the number of bombs that appear in the list
 */
int getBombCount( neighbor* neighbors) {
	return countBombs(neighbors, 0);
}

/*
 * recurses through list, counting bomb occurances
 */
int countBombs( neighbor* neighbors, int count) {
	if( neighbors == NULL) {
		return count;
	} else {
		if( neighbors->value.status == 'b') {
			count++;
		}
		return countBombs(neighbors->next, count);
	}
}
