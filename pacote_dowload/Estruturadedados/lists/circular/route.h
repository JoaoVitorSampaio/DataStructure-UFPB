#ifndef ROUTE_H // checks if the header has already been included
#define ROUTE_H // if not, define the header

#include "create.h" // for vector, linked list and double linked list

// function prototypes for vector
/**
 * @brief Clean the entire list.
 * @param vector A pointer to the vector list.
 * @return void
 */
void clean_vector_list(struct vector*);

/**
 * @brief Search for an element in the list.
 * @param vector A pointer to the vector list.
 * @return void The index of the element if found, otherwise -1.
 */
void search_vector_list(struct vector*);

/**
 * @brief Print all elements in the list.
 * @param vector A pointer to the vector list.
 * @return void
 */
void print_vector_list(struct vector*);


// function prototypes for linked list
/**
 * @brief Clean the entire list.
 * @param list A double pointer to the head of the linked list.
 * @return void
 */
void clean_linked_list(struct node**);

/**
 * @brief Search for an element in the list.
 * @param list A double pointer to the head of the linked list.
 * @return void
 */
void search_linked_list(struct node**);

/**
 * @brief Print all elements in the list from the beginning to the end.
 * @param list A double pointer to the head of the linked list.
 * @return void
 */
void print_linked_list(struct node**);


// function prototypes for double linked list
/**
 * @brief Clean the entire list.
 * @param list A double pointer to the head of the linked list.
 * @return void
 */
void clean_double_linked_list(struct list**);

/**
 * @brief Search for an element in the list.
 * @param list A double pointer to the head of the linked list.
 * @return void
 */
void search_double_linked_list(struct list**);

/**
 * @brief Print all elements in the list from the beginning to the end.
 * @param list A double pointer to the head of the linked list.
 * @return void
 */
void print1_double_linked_list(struct list**);

/**
 * @brief Print all elements in the list from the end to the beginning.
 * @param list A double pointer to the head of the linked list.
 * @return void
 */
void print2_double_linked_list(struct list**);

#endif // end of the header guard