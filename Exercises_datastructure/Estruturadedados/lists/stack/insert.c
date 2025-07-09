/**
 * @file insert.c
 * @brief This file implements the insertion functions for the stack.
 * 
 * @author João Vitor Sampaio
 * @version 2.0
 * @date 2025-03-10
 */

#include "insert.h" // include the header file with the function prototypes

// list by vector
// inserts a new element at the end of the vector
void push_vector(struct vector *l) {
    if (vector_full(*l)) { //if the list is full
        printf("The list is full.\n"); // prints a message
        return; // returns
    }
    int data; // creates a variable to store the data
    printf("Enter the data: "); // asks the user for the data
    scanf("%d", &data); // reads the data
    l->data[l->ctr] = data; // inserts the data in the vector
    l->ctr++; // increments the control of the vector
}

// list by linked list
// inserts a new element at the beginning of the linked list
void push_linked_list(struct node **l) {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);
    struct node *new_node = (struct node*)malloc(sizeof(struct node)); // allocates memory for the new node
    new_node->data = data; // sets the data of the new node
    new_node->next = *l; // sets the next pointer of the new node
    *l = new_node; // sets the head pointer to the new node
}
