#ifndef CREATE_H // checks if the header has already been included
#define CREATE_H // if not, define the header

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

/**
 * @brief Defines the structure for a node in the linked list.
 *
 * @param data The data stored in the node.
 * @param next A pointer to the next node.
 */
struct knot {
    int data;
    struct knot *next;
};

/**
 * @brief Initializes the linked list to be empty.
 *
 * @param l A double pointer to the head of the linked list.
 * @return void
 */
// initialize the list to be empty
void create(struct knot**);

/**
 * @brief Checks if the list is empty
 * @param knot A pointer to the head of the linked list.
 * @return int Returns 1 if the list is empty, 0 otherwise. *
 */
int is_empty (struct knot*);

#endif // end of the header guard