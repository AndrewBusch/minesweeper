#ifndef LIST_H
#define LIST_H

#include "stdlib.h"
#include "stdio.h"

// TODO: REFACTOR TO REPLACE CHARS WITH SQUARES
typedef struct{
	char status;

	int row;
	int column;
} square;

// node for linked list
typedef struct _neighbor{
	struct _neighbor *next;
	square value;
} neighbor;

void printList( neighbor* list);
neighbor* addNeighbor( neighbor* list, square value);
neighbor* remNeighbor( neighbor* list);

#endif
