#ifndef ROUTE_H // checks if the header has already been included
#define ROUTE_H // if not, define the header

#include "create.h"

/**
 * @brief Clean the entire list.
 * @param knot A double pointer to the head of the linked list.
 * @return void
 */
void clean(struct knot**);

/**
 * @brief Search for an element in the list.
 * @param knot A pointer to the head of the linked list.
 * @return void
 */
void search(struct knot*);

/**
 * @brief Print all elements in the list.
 * @param knot A pointer to the head of the linked list.
 * @return void
 */
void print(struct knot*);

#endif // end of the header guard