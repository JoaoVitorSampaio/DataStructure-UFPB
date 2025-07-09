#ifndef INSERT_H // checks if the header has already been included
#define INSERT_H // if not, define the header

#include "create.h" // include the header file with the function prototypes

// list by vector
/**
 * @brief Inserts a new element at the end of the vector.
 * @param l A pointer to the vector.
 * @return void
 */
void push_vector(struct vector *l);

// list by linked list
/**
 * @brief Inserts a new element at the beginning of the linked list.
 * @param l A pointer to the head of the linked list.
 * @return void
 */
void push_linked_list(struct node **l);

#endif // end of the header guard