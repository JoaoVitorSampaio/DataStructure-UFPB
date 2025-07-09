#ifndef INSERT_H // checks if the header has already been included
#define INSERT_H // if not, define the header

#include "create.h"

/**
 * @brief Inserts a new element at the beginning of the list
 * 
 * @param list A double pointer to the head of the list.
 * @return void
 */
void insert_start(struct list**);

/**
 * @brief Inserts a new element at the end of the list
 * 
 * @param list A double pointer to the head of the list.
 * @return void
 */
void_insert_midddle(struct list**);

/**
 * @brief Inserts a new element at the end of the list
 * 
 * @param list A double pointer to the head of the list.
 * @return void
 */
void insert_end(struct list**);

#endif // end of the header guard