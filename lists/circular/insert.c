/**
 * @file insert.c
 * @brief This file implements the insertion functions for the circular list.
 * 
 * @author João Vitor Sampaio
 * @version 2.0
 * @date 2025-03-01
 */

 #include "insert.h" // include the header file with the function prototypes

 int data;
 
 // circular list by vector
 // inserts a new element at the beginning of the vector
 void insert_begin_vector(struct vector *l) {
     printf("Data: ");
     scanf("%d", &data);
     if (vector_full(*l)) { // if the list is full
         printf("The list is full.\n"); // prints a message
         return; // returns
     }
     l->head = (l->head - 1 + SIZE) % SIZE; // decrements the head
     l->data[l->head] = data; // inserts the data
     l->size++; // increments the size
 }
 
 // inserts a new element at the middle of the vector
 void insert_middle_vector(struct vector *l) {
     printf("Data: ");
     scanf("%d", &data);
     if (vector_full(*l)) { // if the list is full
         printf("The list is full.\n"); // prints a message
         return; // returns
     }
     int i = l->head; // initializes the index
     for (int j = 0; j < l->size / 2; j++) { // iterates over the first half of the list
         i = (i + 1) % SIZE; // increments the index
     }
     for (int j = 0; j < l->size / 2; j++) { // iterates over the second half of the list
         l->data[(i + 1) % SIZE] = l->data[i]; // shifts the elements
         i = (i - 1 + SIZE) % SIZE; // decrements the index
     }
     l->data[i] = data; // inserts the data
     l->size++; // increments the size
 }
 
 // inserts a new element at the end of the vector
 void insert_end_vector(struct vector *l) {
     printf("Data: ");
     scanf("%d", &data);
     if (vector_full(*l)) { // if the list is full
         printf("The list is full.\n"); // prints a message
         return; // returns
     }
     l->data[l->tail] = data; // inserts the data
     l->tail = (l->tail + 1) % SIZE; // increments the tail
     l->size++; // increments the size
 }
 
 
 // circular list by linked list
 // inserts a new element at the beginning of the linked list
 void insert_begin_linked_list(struct node **l) {
     printf("Data: ");
     scanf("%d", &data);
     struct node *new_node; // creates a new node
     new_node = (struct node*)malloc(sizeof(struct node)); // allocates memory for the new node
     new_node->data = data; // inserts the data
     if (linked_list_empty(*l)) { // if the list is empty
         new_node->next = new_node; // points to itself
         *l = new_node; // sets the head pointer to the new node
     } 
     else { // if the list is not empty
         struct node *last = *l; // creates a pointer to the last node
         while (last->next != *l) { // iterates over the list
             last = last->next; // moves to the next node
         }
         new_node->next = *l; // points to the head
         last->next = new_node; // inserts the new node
         *l = new_node; // sets the head pointer to the new node
     }
 }
 
 // inserts a new element at the middle of the linked list
 void insert_middle_linked_list(struct node **l) {
     printf("Data: ");
     scanf("%d", &data);
     struct node *new_node; // creates a new node
     new_node = (struct node*)malloc(sizeof(struct node)); // allocates memory for the new node
     new_node->data = data; // inserts the data
     if (linked_list_empty(*l)) { // if the list is empty
         new_node->next = new_node; // points to itself
         *l = new_node; // sets the head pointer to the new node
     } 
     else { // if the list is not empty
         struct node *slow = *l; // creates a pointer to the slow node
         struct node *fast = *l; // creates a pointer to the fast node
         while (fast->next != *l && fast->next->next != *l) { // iterates over the list
             slow = slow->next; // moves the slow pointer
             fast = fast->next->next; // moves the fast pointer
         }
         new_node->next = slow->next; // points to the next node
         slow->next = new_node; // inserts the new node
     }
 }
 
 // inserts a new element at the end of the linked list
 void insert_end_linked_list(struct node **l) {
     printf("Data: ");
     scanf("%d", &data);
     struct node *new_node; // creates a new node
     new_node = (struct node*)malloc(sizeof(struct node)); // allocates memory for the new node
     new_node->data = data; // inserts the data
     if (linked_list_empty(*l)) { // if the list is empty
         new_node->next = new_node; // points to itself
         *l = new_node; // sets the head pointer to the new node
     } 
     else { // if the list is not empty
         struct node *last = *l; // creates a pointer to the last node
         while (last->next != *l) { // iterates over the list
             last = last->next; // moves to the next node
         }
         new_node->next = *l; // points to the head
         last->next = new_node; // inserts the new node
     }
 }
 
 
 // circular list by double linked list
 // inserts a new element at the beginning of the double linked list
 void insert_begin_double_linked_list(struct list **l) {
     printf("Data: ");
     scanf("%d", &data);
     struct dnode *new_node; // creates a new node
     create_double_linked_node(&new_node); // creates a new node
     new_node->data = data; // inserts the data
     if (double_linked_list_empty(l)) { // if the list is empty
         new_node->next = new_node; // points to itself
         new_node->prev = new_node; // points to itself
         (*l)->begin = new_node; // sets the begin pointer to the new node
         (*l)->end = new_node; // sets the end pointer to the new node
     } 
     else { // if the list is not empty
         new_node->next = (*l)->begin; // points to the head
         new_node->prev = (*l)->end; // points to the tail
         (*l)->begin->prev = new_node; // inserts the new node
         (*l)->end->next = new_node; // inserts the new node
         (*l)->begin = new_node; // sets the begin pointer to the new node
     }
 }
 
 // inserts a new element at the middle of the double linked list
 void insert_middle_double_linked_list(struct list **l) {
     printf("Data: ");
     scanf("%d", &data);
     struct dnode *new_node; // creates a new node
     create_double_linked_node(&new_node); // creates a new node
     new_node->data = data; // inserts the data
     if (double_linked_list_empty(l)) { // if the list is empty
         new_node->next = new_node; // points to itself
         new_node->prev = new_node; // points to itself
         (*l)->begin = new_node; // sets the begin pointer to the new node
         (*l)->end = new_node; // sets the end pointer to the new node
     } 
     else { // if the list is not empty
         struct dnode *slow = (*l)->begin; // creates a pointer to the slow node
         struct dnode *fast = (*l)->begin; // creates a pointer to the fast node
         while (fast != (*l)->end && fast->next != (*l)->end) { // iterates over the list
             slow = slow->next; // moves the slow pointer
             fast = fast->next->next; // moves the fast pointer
         }
         new_node->next = slow->next; // points to the next node
         new_node->prev = slow; // points to the slow node
         slow->next->prev = new_node; // inserts the new node
         slow->next = new_node; // inserts the new node
     }
 }
 
 // inserts a new element at the end of the double linked list
 void insert_end_double_linked_list(struct list **l) {
     printf("Data: ");
     scanf("%d", &data);
     struct dnode *new_node; // creates a new node
     create_double_linked_node(&new_node); // creates a new node
     new_node->data = data; // inserts the data
     if (double_linked_list_empty(l)) { // if the list is empty
         new_node->next = new_node; // points to itself
         new_node->prev = new_node; // points to itself
         (*l)->begin = new_node; // sets the begin pointer to the new node
         (*l)->end = new_node; // sets the end pointer to the new node
     } 
     else { // if the list is not empty
         new_node->next = (*l)->begin; // points to the head
         new_node->prev = (*l)->end; // points to the tail
         (*l)->begin->prev = new_node; // inserts the new node
         (*l)->end->next = new_node; // inserts the new node
         (*l)->end = new_node; // sets the end pointer to the new node
     }
 }