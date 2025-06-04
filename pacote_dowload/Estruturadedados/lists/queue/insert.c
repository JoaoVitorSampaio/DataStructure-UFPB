/**
 * @file insert.c
 * @brief This file implements the insertion functions for the queue.
 * 
 * @author João Vitor Sampaio
 * @version 1.0
 * @date 2025-03-17
 */

 #include "insert.h" // include the header file with the function prototypes

 // queue by vector
 // inserts a new element at the end of the vector
 void insert_vector(struct vector *l, int data) {
     int end;
     if (vector_full(l)) {
         printf("Vector is full.\n");
         return;
     }
     end = (l->start + l->n) % SIZE; // calculates the position of the end of the vector
     l->data[end] = data; // inserts the data at the end of the vector
     l->n++; // increments the number of elements in the vector
 }
 
 // queue by linked list
 // inserts a new element at the end of the linked list
 void insert_linked_list(struct queue **l, int data) {
     struct node *new_node = (struct node *)malloc(sizeof(struct node)); // allocates memory for the new node
     new_node->data = data; // sets the data of the new node
     new_node->next = NULL; // sets the next pointer of the new node to NULL
     if ((*l)->tail != NULL) { // checks if the linked list not is empty
         (*l)->tail->next = new_node; // sets the head of the linked list to the new node
     }
     else {
         (*l)->head = new_node; // sets the head of the linked list to the new node
     }
     (*l)->tail = new_node; // sets the tail of the linked list to the new node
 }
 
 // queue by doubly linked list
 // inserts a new element at the end of the doubly linked list
 void insert_doubly_linked_list(struct dqueue **l, int data) {
     struct dnode *new_node = (struct dnode *)malloc(sizeof(struct dnode)); // allocates memory for the new node
     new_node->data = data; // sets the data of the new node
     new_node->next = NULL; // sets the next pointer of the new node to NULL
     new_node->prev = (*l)->tail; // sets the previous pointer of the new node to the tail of the doubly linked list
     if ((*l)->tail != NULL) { // checks if the doubly linked list not is empty
         (*l)->tail->next = new_node; // sets the next pointer of the tail of the doubly linked list to the new node
     }
     else {
         (*l)->head = new_node; // sets the head of the doubly linked list to the new node
     }
     (*l)->tail = new_node; // sets the tail of the doubly linked list to the new node
 }