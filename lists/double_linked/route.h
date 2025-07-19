#ifndef ROUTE_H // checks if the header has already been included
#define ROUTE_H // if not, define the header

#include "create.h"

/**
 * @brief Clean the entire list.
 * @param list A double pointer to the head of the linked list.
 * @return void
 */
void clean(struct list**);

/**
 * @brief Search for an element in the list.
 * @param list A double pointer to the head of the linked list.
 * @return void
 */
void search(struct list**);

/**
 * @brief Print all elements in the list from the beginning to the end.
 * @param list A double pointer to the head of the linked list.
 * @return void
 */
void print_begin(struct list**);

/**
 * @brief Print all elements in the list from the end to the beginning.
 * @param list A double pointer to the head of the linked list.
 * @return void
 */
void print_end(struct list**);

#endif // end of the header guard