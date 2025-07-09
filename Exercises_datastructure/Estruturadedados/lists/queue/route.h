#ifndef ROUTE_H // checks if the header has already been included
#define ROUTE_H // if not, define the header

#include "create.h"

// queue by vector
/**
 * @brief Consult the element at the beginning of the list.
 * @param vector A pointer to the vector list.
 * @return The element at the beginning of the list.
 */
int consult_vector_list(struct vector*);

/**
 * @brief Clean the entire list.
 * @param vector A pointer to the vector list.
 * @return void
 */
void clean_vector_list(struct vector*);

/**
 * @brief Print all elements in the list.
 * @param vector A pointer to the vector list.
 * @return void
 */
void print_vector_list(struct vector*);


// queue by linked list
/**
 * @brief Consult the element at the beginning of the list.
 * @param list A pointer to the head of the queue.
 * @return The element at the beginning of the list.
 */
int consult_linked_list(struct queue*);

/**
 * @brief Clean the entire list.
 * @param list A double pointer to the head of the queue.
 * @return void
 */
void clean_linked_list(struct queue**);

/**
 * @brief Print all elements in the list from the beginning to the end.
 * @param list A pointer to the head of the queue.
 * @return void
 */
void print_linked_list(struct queue*);


// queue by doubly linked list
/**
 * @brief Consult the element at the beginning of the list.
 * @param list A pointer to the head of the queue.
 * @return The element at the beginning of the list.
 */
int consult_doubly_linked_list(struct dqueue*);

/**
 * @brief Clean the entire list.
 * @param list A double pointer to the head of the queue.
 * @return void
 */
void clean_doubly_linked_list(struct dqueue**);

/**
 * @brief Print all elements in the list from the beginning to the end.
 * @param list A pointer to the head of the queue.
 * @return void
 */
void print_doubly_linked_list(struct dqueue*);

#endif // end of the header guard