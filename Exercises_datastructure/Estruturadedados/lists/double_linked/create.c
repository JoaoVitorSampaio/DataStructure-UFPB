/**
 * @file create.c
 * @brief Implementation of the function to create a linked list.
 * 
 * @author João Vitor Sampaio
 * @version 1.0
 * @date 2025-02-24
 */

#include "create.h" // Include the header file with the function prototypes

// initializes the linked list to be empty
void create_list(struct list **l) {
    *l = (struct list*)malloc(sizeof(struct list)); // Allocates memory for the list
    (*l)->begin = NULL; // Sets the beginning of the list to NULL
    (*l)->end = NULL; // Sets the end of the list to NULL
}

// creates a new node in the linked list
void create_node(struct node **n) {
    *n = (struct node*)malloc(sizeof(struct node)); // Allocates memory for the node
    (*n)->prev = NULL; // Sets the previous node to NULL
    (*n)->next = NULL; // Sets the next node to NULL
}

// checks if the linked list is empty
int is_empty(struct list **l) {
    return ((*l)->begin == NULL && (*l)->end == NULL); // Returns 1 if the list is empty, 0 otherwise
}