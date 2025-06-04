/**
 * @file create.c
 * @brief Implementation of the function to create a circular list.
 * 
 * @author João Vitor Sampaio	
 * @version 1.0
 * @date 2025-02-26
 */

#include "create.h" // Include the header file with the function prototypes

// circular list by vector
// initialize the list to be empty
void create_vector_list(struct vector *l) {
    l->head = 0; // set the head of the list to 0
    l->tail = 0; // set the tail of the list to 0
    l->size = 0; // set the size of the list to 0
 }

// checks if the list is full
char vector_full(struct vector l) {
    return (l.size == SIZE); // return 1 if the list is full, 0 otherwise
 }

// checks if the list is empty
char vector_empty(struct vector l) {
    return (l.size == 0); // return 1 if the list is empty, 0 otherwise
}


// circular list by linked list
// initialize the linked list to be empty
void create_linked_list(struct node **l) {
    *l = NULL; // set the head pointer of the list to NULL
}

// checks if the linked list is empty
char linked_list_empty(struct node *l) {
    return (l == NULL); // return 1 if the list is empty, 0 otherwise
}

// circular list by double linked list
// initialize the double linked list to be empty
void create_double_linked_list(struct list **l) {
    *l = (struct list *)malloc(sizeof(struct list)); // allocates memory for the list
    (*l)->begin = NULL; // sets the begin pointer to NULL
    (*l)->end = NULL; // sets the end pointer to NULL
}

// creates a new node in the linked list
void create_double_linked_node(struct dnode **n) {
    *n = (struct dnode*)malloc(sizeof(struct dnode)); // allocates memory for the node
    (*n)->prev = NULL; // sets the prev pointer to NULL
    (*n)->next =  NULL; // sets the next pointer to NULL
}

// checks if the double linked list is empty
char double_linked_list_empty(struct list **l) {
    return ((*l)->begin == NULL && (*l)->end == NULL); // return 1 if the list is empty, 0 otherwise
}
