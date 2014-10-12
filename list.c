/*
 * basic linked list for keeping track of neighbors in minesweeper
 * Andrew Busch
 */

#include "list.h"

/*
 * print the list of neighbors
 */
void printNeighbors( neighbor* list) {

	if( list != NULL){
		printf("char value: %c\n", list->value.status);
		printNeighbors( list->next);
	}
}

/*
 * Add a neighbor to a given list
 */
neighbor* addNeighbor( neighbor* list, square value) {

	if( list == NULL) {
		list = (neighbor*) malloc( sizeof( neighbor));
		list->next = NULL;
		list->value = value;
		return list;
	} else {
		list->next = addNeighbor( list->next, value);
		return list;
	}
}

/*
 * remove the top neighbor from the list
 */
neighbor* remNeighbor( neighbor* list) {

	if( list != NULL)
		return list->next;
	else
		return NULL;
}
