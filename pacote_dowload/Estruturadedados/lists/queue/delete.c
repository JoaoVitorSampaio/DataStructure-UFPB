/**
 * @file delete.c
 * @brief This file implements the deletion functions for the queue.
 * 
 * @author João Vitor Sampaio
 * @version 1.1
 * @date 2025-03-17
 */

 #include "delete.h" // include the header file with the function prototypes

 // queue by vector
 // deletes the first element of the vector
 int remove_vector(struct vector *l) {
     int v; // creates a variable to store the value
     if (vector_empty(*l)) { // if the list is empty
         printf("The queue is empty.\n"); // prints a message
         return -1; // returns
     }
     v = l->data[l->start]; // stores the value of the first element
     l->start = (l->start + 1) % SIZE; // increments the start index
     l->n--; // decrements the number of elements
     return v; // returns the value
 }
 
 // queue by linked list
 // deletes the first element of the linked list
 int remove_linked_list(struct queue *l) {
     struct node *temp; // creates a pointer to a node
     int v; // creates a variable to store the value
     if (linked_list_empty(l)) { // if the list is empty
         printf("The queue is empty.\n"); // prints a message
         return -1; // returns
     }
     temp = l->head; // pointer to the head
     v = temp->data; // stores the value of the first element
     l->head = l->head->next; // moves the head pointer to the next node
     if (l->head == NULL) { // if there is only one element
         l->tail = NULL; // sets the tail pointer to NULL
     }
     free(temp); // frees the memory
     return v; // returns the value
 }
 
 // queue by doubly linked list
 // deletes the first element of the doubly linked list
 int remove_doubly_linked_list(struct dqueue *l) {
     struct dnode *temp; // creates a pointer to a node
     int v; // creates a variable to store the value
     if (doubly_linked_list_empty(l)) { // if the list is empty
         printf("The queue is empty.\n"); // prints a message
         return -1; // returns
     }
     temp = l->head; // pointer to the head
     v = temp->data; // stores the value of the first element
     l->head = l->head->next; // moves the head pointer to the next node
     if (l->head == NULL) { // if there is only one element
         l->tail = NULL; // sets the tail pointer to NULL
     }
     else { // if there are more than one element
         l->head->prev = NULL; // sets the previous pointer to NULL
     }
     free(temp); // frees the memory
     return v; // returns the value
 }