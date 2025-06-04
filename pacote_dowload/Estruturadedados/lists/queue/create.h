#ifndef CREATE_H // checks if the header has already been included
#define CREATE_H // if not, define the header

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

#define SIZE 10 // size of the vector

// queue by vector
/**
 * @brief Defines the structure for a vector in a circular list.
 * @param n The number of elements in the vector.
 * @param start The index of the first element in the vector.
 * @param data The data stored in the vector.
 */
struct vector {
    int n; // number of elements
    int start; // index of the first element
    int data[SIZE]; // data
};

/**
 * @brief Initializes the list to be empty.
 * @param l A double pointer to the head of the vector.
 * @return void
 */
void create_vector_list(struct vector **l);

/**
 * @brief Checks if the list is empty.
 * @param l pointer to the head of the vector.
 * @return int 1 if the list is empty, 0 otherwise.
 */
int vector_empty(struct vector l);

/**
 * @brief Checks if the list is full.
 * @param l The vector.
 * @return int 1 if the list is full, 0 otherwise.
 */
int vector_full(struct vector *l);


// queue by linked list
/**
 * @brief Defines the structure for a node in the linked list.
 * @param data The data stored in the node.
 * @param next A pointer to the next node.
 */
struct node {
    int data;
    struct node *next;
};

/**
 * @brief Defines the structure for a queue in a linked list.
 * @param head A pointer to the first node.
 * @param tail A pointer to the last node.
 */
struct queue {
    struct node *head;
    struct node *tail;
};

/**
 * @brief Initializes the linked list to be empty.
 * @param l A double pointer to the head of the linked list.
 * @return void
 */
void create_linked_list(struct queue **l);

/**
 * @brief Checks if the linked list is empty.
 * @param l A pointer to the head of the linked list.
 * @return int 1 if the list is empty, 0 otherwise.
 */
int linked_list_empty(struct queue *l);


// queue by doubly linked list
/**
 * @brief Defines the structure for a node in the doubly linked list.
 * @param data The data stored in the node.
 * @param next A pointer to the next node.
 * @param prev A pointer to the previous node.
 */
struct dnode {
    int data;
    struct dnode *next;
    struct dnode *prev;
};

/**
 * @brief Defines the structure for a queue in a doubly linked list.
 * @param head A pointer to the first node.
 * @param tail A pointer to the last node.
 */
struct dqueue {
    struct dnode *head;
    struct dnode *tail;
};

/**
 * @brief Initializes the doubly linked list to be empty.
 * @param l A double pointer to the head of the doubly linked list.
 * @return void
 */
void create_doubly_linked_list(struct dqueue **l);

/**
 * @brief Checks if the doubly linked list is empty.
 * @param l A pointer to the head of the doubly linked list.
 * @return int 1 if the list is empty, 0 otherwise.
 */
int doubly_linked_list_empty(struct dqueue *l);

#endif // end of the header guard