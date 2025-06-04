#ifndef DELETE_H // checks if the header has already been included
#define DELETE_H // if not, define the header

#include "create.h"

/**
 * @brief Deletes the first element of the list
 * @param knot A double pointer to the head of the linked list.
 * @return void
 */
 void delete_start(struct knot**);

/**
* @brief Deletes an element in the middle of the list
* @param knot A double pointer to the head of the linked list.
* @return void
*/
void delete_middle(struct knot**);

/**
 * @brief Deletes the last element of the list
 * @param knot A double pointer to the head of the linked list.
 * @return void
 */
 void delete_end(struct knot**);

#endif // end of the header guard
