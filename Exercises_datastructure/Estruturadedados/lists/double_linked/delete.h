#ifndef DELETE_H // checks if the header has already been included
#define DELETE_H // if not, define the header

#include "create.h"

/**
 * @brief Deletes the first element of the list
 * 
 * @param list A double pointer to the head of the list.
 * @return void
 */
void delete_start(struct list **l);

/**
 * @brief Deletes a node in the middle of a linked list
 * 
 * @param list A double pointer to the head of the list.
 * @return void
 */
void delete_middle(struct list **l);

/**
 * @brief Deletes the last element of the list
 * 
 * @param list A double pointer to the head of the list.
 * @return void
 */
void delete_end(struct list **l);

#endif // end of the header guard