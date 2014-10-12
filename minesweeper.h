#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "time.h"
#include "list.h"
#include "stdlib.h"
#include "stdio.h"

#define rowSize 10
#define columnSize 10
#define numMines 20

void printBoard( square (*board)[columnSize] );
void placeMines( square (*board)[columnSize] );
void wipeBoard( square (*board)[columnSize] );
void fillValues( square (*board)[columnSize] );
neighbor* getNeighbors( square (*board)[columnSize], int row, int column);
int getBombCount( neighbor* neighbors);
int countBombs( neighbor* neighbors, int count);

#endif
