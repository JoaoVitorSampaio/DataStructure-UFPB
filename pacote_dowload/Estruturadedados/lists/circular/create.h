#ifndef  CREATE_H // check if the header has already beens included
#define  CREATE_H // if not, define the header

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

#define SIZE 9 // define the size of the vector

// circular list by vector
/**
 * @brief Defines the structure for a vector in a circular list.
 * 
 * @param data The data stored in the vector.
 * @param head The index of the head element.
 * @param tail The index of the tail element.
 * @param size The current size of the vector. * 
 */
struct vector {
    int data[SIZE]; // the data stored in the vector
    int head, tail, size; // control variables
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
 * @param l The vector to be checked.
 * @return char 1 if the list is full, 0 otherwise.
 */
char vector_full(struct vector l);

/**
 * @brief Checks if the list is empty.
 * 
 * @param l The vector to be checked.
 * @return char 1 if the list is empty, 0 otherwise.
 */
char vector_empty(struct vector l);

// circular list by linked list
/**
 * @brief Defines the structure for a node in the linked list.
 * 
 * @param data The data stored in the node.
 * @param next A pointer to the next node.
 */
struct node {
    int data; // the data stored in the node
    struct node *next; // a pointer to the next node
};

/**
 * @brief Initializes the linked list to be empty.
 * 
 * @param l A pointer to the head of the linked list.
 * @return void
 */
void create_linked_list(struct node **l);

/**
 * @brief Checks if the linked list is empty.
 * 
 * @param l The head of the linked list.
 * @return char 1 if the list is empty, 0 otherwise.
 */
char linked_list_empty(struct node *l);

// circular list by double linked list
/**
 * @brief Defines the structure for a node in the linked list.
 * 
 * @param prev A pointer to the previous node.
 * @param data The data stored in the node.
 * @param next A pointer to the next node.
 */
struct dnode {
    struct dnode *prev;
    int data;
    struct dnode *next;
};

/**
 * @brief Defines the structure for a list with two pointers in the linked list.
 * 
 * @param begin A pointer to the first node.
 * @param end A pointer to the last node.
 */
struct list {
    struct dnode *begin;
    struct dnode *end;
};

/**
 * @brief Initializes the linked list to be empty.
 * 
 * @param l A double pointer to the head of the linked list.
 * @return void
 */
void create_double_linked_list(struct list **l);

/**
 * @brief Creates a new node in the linked list.
 * 
 * @param n A double pointer to the node to be created.
 * @return void
 */
void create_double_linked_node(struct dnode **n);

/**
 * @brief Checks if the double linked list is empty.
 * 
 * @param l A double pointer to the head of the linked list.
 * @return char 1 if the list is empty, 0 otherwise.
 */
char double_linked_list_empty(struct list **l);

#endif // end of the header guard