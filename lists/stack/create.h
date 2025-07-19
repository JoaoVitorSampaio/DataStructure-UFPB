#ifndef CREATE_H // checks if the header has already been included
#define CREATE_H // if not, define the header

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

#define SIZE 10 // size of the vector

// list by vector
/**
 * @brief Defines the structure for a vector in a circular list.
 * 
 * @param data The data stored in the vector.
 * @param ctr The control variable.
 */
struct vector {
    int data[SIZE]; // data
    int ctr; // control variable
};

/**
 * @brief Initializes the list to be empty.
 * 
 * @param l A pointer to the head of the vector.
 * @return void
 */
void create_vector_list(struct vector *l);

/**
 * @brief Checks if the list is full.
 * 
 * @param l The vector.
 * @return int 1 if the list is full, 0 otherwise.
 */
int vector_full(struct vector l);

/**
 * @brief Checks if the list is empty.
 * 
 * @param l The vector.
 * @return int 1 if the list is empty, 0 otherwise.
 */
int vector_empty(struct vector l);


// list by linked list
/**
 * @brief Defines the structure for a node in the linked list.
 * 
 * @param data The data stored in the node.
 * @param next A pointer to the next node.
 */
struct node {
    int data;
    struct node *next;
};

/**
 * @brief Initializes the linked list to be empty.
 * 
 * @param l A double pointer to the head of the linked list.
 * @return void
 */
void create_linked_list(struct node **l);

/**
 * @brief Checks if the linked list is empty.
 * 
 * @param l A pointer to the head of the linked list.
 * @return int 1 if the list is empty, 0 otherwise.
 */
int linked_list_empty(struct node *l);

#endif // end of the header guard