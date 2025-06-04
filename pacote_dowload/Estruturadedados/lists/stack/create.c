/**
 * @file create.c
 * @brief Implementation of the function to create a stack.
 * 
 * @author João Vitor Sampaio
 * @version 1.0
 * @date 2025-03-10
 */

 #include "create.h" // include the header file with the function prototypes

 // list by vector
 // initializes the list to be empty
 void create_vector_list(struct vector *l) {
     l->ctr = 0; // sets the control to 0
 }
 
 // checks if the list is full
 int vector_full(struct vector l) {
     return (l.ctr == SIZE); // returns 1 if the control is equal to SIZE
 }
 
 // checks if the list is empty
 int vector_empty(struct vector l) {
     return (l.ctr == 0); // returns 1 if the control is 0
 }
 
 
 // list by linked list
 // initializes the linked list to be empty
 void create_linked_list(struct node **l) {
     *l = NULL; // sets the head pointer to NULL
 }
 
 // checks if the linked list is empty
 int linked_list_empty(struct node *l) {
     return (l == NULL); // returns 1 if the head pointer is NULL
 }