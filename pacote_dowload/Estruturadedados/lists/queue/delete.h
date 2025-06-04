#ifndef DELETE_H // checks if the header has already been included
#define DELETE_H // if not, define the header

#include "create.h"

// queue by vector
/**
 * @brief Removes the first element of the queue
 * @param l pointer to the queue
 * @return int
 */
int remove_vector(struct vector *l);

// queue by linked list
/**
 * @brief Removes the first element of the queue
 * @param l pointer to the queue
 * @return int 
 */
int remove_linked_list(struct queue *l);

// queue by doubly linked list
/**
 * @brief Removes the first element of the queue
 * @param l pointer to the queue
 * @return int
 */
int remove_doubly_linked_list(struct dqueue *l);

#endif // end of the header guard