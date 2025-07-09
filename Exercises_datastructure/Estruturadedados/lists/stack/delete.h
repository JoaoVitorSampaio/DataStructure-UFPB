#ifndef DELETE_H // checks if the header has already been included
#define DELETE_H // if not, define the header

#include "create.h" // include the header file with the function prototypes

// list by vector
/**
 * @brief Deletes the last element of the vector.
 * @param l A pointer to the vector.
 * @return void 
 */
void pop_vector(struct vector *L);

// list by linked list
/**
 * @brief Deletes the first element of the linked list.
 * @param l A pointer to the head of the linked list.
 * @return void
 */
void pop_linked_list(struct node **l);

#endif // end of the header guard