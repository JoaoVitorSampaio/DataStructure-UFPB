/**
 * @file delete.c
 * @brief This file implements the deletion functions for the stack.
 * 
 * @author João Vitor Sampaio
 * @version 1.1
 * @date 2025-03-10
 */

 #include "delete.h" // include the header file with the function prototypes

 // list by vector
 // deletes the last element of the vector
 void pop_vector(struct vector *l) {
     if (vector_empty(*l)) { // if the list is empty
         printf("The list is empty.\n"); // prints a message
         return; // returns
     }
     l->ctr--; // decrement the control of the vector
 }
 
 
 // list by linked list
 // deletes the first element of the linked list
 void pop_linked_list(struct node **l) {
     if (linked_list_empty(*l)) { // if the list is empty
         printf("The list is empty.\n"); // prints a message
         return; // returns
     }
     struct node *temp = *l; // creates a pointer to the head
     while (temp->next != *l) { // iterates over the list
         temp = temp->next; // moves to the next node
     }
     if (temp == *l) { // if there is only one element
         free(temp); // frees the memory
         *l = NULL; // sets the head pointer to NULL
     }
     else { // if there are more than one element
         temp->next = (*l)->next; // removes the first element
         free(*l); // frees the memory
         *l = temp->next; // sets the head pointer to the next node
     }
 }