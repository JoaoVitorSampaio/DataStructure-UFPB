/**
 * @file delete.c
 * @brief This file implements the deletion functions for the circular list.
 * 
 * @author João Vitor Sampaio
 * @version 2.0
 * @date 2025-03-09
 */

 #include "delete.h" // include the header file with the function prototypes

 // circular list by vector
 // deletes the first element of the vector
 void delete_begin_vector(struct vector *l) {
     if (vector_empty(*l)) { // if the list is empty
         printf("The list is empty.\n"); // prints a message
         return; // returns
     }
     l->head = (l->head + 1) % SIZE; // increments the head
     l->size--; // decrements the size
 }
 
 // deletes the middle element of the vector
 void delete_middle_vector(struct vector *l) {
     if (vector_empty(*l)) { // if the list is empty
         printf("The list is empty.\n"); // prints a message
         return; // returns
     }
     int i = l->head; // initializes the index
     for (int j = 0; j < l->size / 2; j++) { // iterates over the first half of the list
         i = (i + 1) % SIZE; // increments the index
     }
     for (int j = 0; j < l->size / 2; j++) { // iterates over the second half of the list
         l->data[i] = l->data[(i + 1) % SIZE]; // shifts the elements
         i = (i + 1) % SIZE; // increments the index
     }
     l->size--; // decrements the size
 }
 
 // deletes the last element of the vector
 void delete_end_vector(struct vector *l) {
     if (vector_empty(*l)) { // if the list is empty
         printf("The list is empty.\n"); // prints a message
         return; // returns
     }
     l->tail = (l->tail - 1 + SIZE) % SIZE; // decrements the tail
     l->size--; // decrements the size
 }
 
 
 // circular list by linked list
 // deletes the first element of the linked list
 void delete_begin_linked_list(struct node **l) {
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
 
 // deletes the middle element of the linked list
 void delete_middle_linked_list(struct node **l) {
     if (linked_list_empty(*l)) { // if the list is empty
         printf("The list is empty.\n"); // prints a message
         return; // returns
     }
     struct node *slow = *l; // creates a pointer to the slow node
     struct node *fast = *l; // creates a pointer to the fast node
     struct node *prev = NULL; // creates a pointer to the previous node
     while (fast != *l && fast->next != *l) { // iterates over the list
         prev = slow; // moves the previous pointer
         slow = slow->next; // moves the slow pointer
         fast = fast->next->next; // moves the fast pointer
     }
     if (prev == NULL) { // if there is only one element
         free(slow); // frees the memory
         *l = NULL; // sets the head pointer to NULL
     }
     else { // if there are more than one element
         prev->next = slow->next; // removes the middle element
         free(slow); // frees the memory
     }
 }
 
 // deletes the last element of the linked list
 void delete_end_linked_list(struct node **l) {
     if (linked_list_empty(*l)) { // if the list is empty
         printf("The list is empty.\n"); // prints a message
         return; // returns
     }
     struct node *temp = *l; // creates a pointer to the head
     struct node *prev = NULL; // creates a pointer to the previous node
     while (temp->next != *l) { // iterates over the list
         prev = temp; // moves the previous pointer
         temp = temp->next; // moves to the next node
     }
     if (prev == NULL) { // if there is only one element
         free(temp); // frees the memory
         *l = NULL; // sets the head pointer to NULL
     }
     else { // if there are more than one element
         prev->next = *l; // removes the last element
         free(temp); // frees the memory
     }
 }
 
 
 // circular list by double linked list
 // deletes the first element of the double linked list
 void delete_begin_double_linked_list(struct list **l) {
     if (double_linked_list_empty(l)) { // if the list is empty
         printf("The list is empty.\n"); // prints a message
         return; // returns
     }
     if ((*l)->begin == (*l)->end) { // if there is only one element
         free((*l)->begin); // frees the memory
         (*l)->begin = NULL; // sets the begin pointer to NULL
         (*l)->end = NULL; // sets the end pointer to NULL
     }
     else { // if there are more than one element
         struct dnode *temp = (*l)->begin; // creates a pointer to the head
         (*l)->begin = (*l)->begin->next; // removes the first element
         (*l)->begin->prev = (*l)->end; // updates the prev pointer
         (*l)->end->next = (*l)->begin; // updates the next pointer
         free(temp); // frees the memory
     }
 }
 
 // deletes the middle element of the double linked list
 void delete_middle_double_linked_list(struct list **l) {
     if (double_linked_list_empty(l)) { // if the list is empty
         printf("The list is empty.\n"); // prints a message
         return; // returns
     }
     struct dnode *slow = (*l)->begin; // creates a pointer to the slow node
     struct dnode *fast = (*l)->begin; // creates a pointer to the fast node
     struct dnode *prev = NULL; // creates a pointer to the previous node
     while (fast != (*l)->end && fast->next != (*l)->end) { // iterates over the list
         prev = slow; // moves the previous pointer
         slow = slow->next; // moves the slow pointer
         fast = fast->next->next; // moves the fast pointer
     }
     if (prev == NULL) { // if there is only one element
         free(slow); // frees the memory
         (*l)->begin = NULL; // sets the begin pointer to NULL
         (*l)->end = NULL; // sets the end pointer to NULL
     }
     else { // if there are more than one element
         prev->next = slow->next; // removes the middle element
         slow->next->prev = prev; // updates the prev pointer
         free(slow); // frees the memory
     }
 }
 
 // deletes the last element of the double linked list
 void delete_end_double_linked_list(struct list **l) {
     if (double_linked_list_empty(l)) { // if the list is empty
         printf("The list is empty.\n"); // prints a message
         return; // returns
     }
     if ((*l)->begin == (*l)->end) { // if there is only one element
         free((*l)->end); // frees the memory
         (*l)->begin = NULL; // sets the begin pointer to NULL
         (*l)->end = NULL; // sets the end pointer to NULL
     }
     else { // if there are more than one element
         struct dnode *temp = (*l)->end; // creates a pointer to the tail
         (*l)->end = (*l)->end->prev; // removes the last element
         (*l)->end->next = (*l)->begin; // updates the next pointer
         (*l)->begin->prev = (*l)->end; // updates the prev pointer
         free(temp); // frees the memory
     }
 }