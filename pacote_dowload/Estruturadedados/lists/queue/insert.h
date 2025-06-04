#ifndef INSERT_H // checks if the header has already been included
#define INSERT_H // if not, define the header

#include "create.h"

// queue by vector
/**
 * @brief Inserts a new element at the end of the vector.
 * @param l A pointer to the vector.
 * @param data The data to be inserted.
 * @return void
 */
void insert_vector(struct vector *l, int data);

// queue by linked list
/**
 * @brief Inserts a new element at the end of the linked list.
 * @param l A pointer to the head of the linked list.
 * @param data The data to be inserted.
 * @return void
 */
void insert_linked_list(struct queue **l, int data);

// queue by doubly linked list
/**
 * @brief Inserts a new element at the end of the doubly linked list.
 * @param l A pointer to the head of the doubly linked list.
 * @param data The data to be inserted.
 * @return void
 */
void insert_doubly_linked_list(struct dqueue **l, int data);

#endif // end of the header guard