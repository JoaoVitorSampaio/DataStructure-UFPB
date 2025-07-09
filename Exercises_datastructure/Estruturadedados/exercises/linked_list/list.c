/**
 * @file list.c
 * @brief Implements the functions defined in list.h
 * 
 * @author João Vitor Sampaio
 * @date 2025-03-15
 * @version 3.0
 */

 #include "list.h"

 // Initializes the linked list to be empty
 void create(struct list **l) {
     *l = (struct list *)malloc(sizeof(struct list));
     if (*l == NULL) {
         printf("Memory allocation failed\n");
         return;
     }
     *l = NULL;
 }
 
 // Checks if the list is empty
 int is_empty(struct list *l) {
     return l->next == NULL;
 }
 
 // Inserts a new node at the end of the list
 void insert_end(struct list **l) {
     int data;
     printf("Enter the data: ");
     scanf("%d", &data);
 
     struct list *new_node = (struct list *)malloc(sizeof(struct list));
     if (new_node == NULL) {
         printf("Memory allocation failed\n");
         return;
     }
 
     // Initialize the new node
     new_node->data = data;
     new_node->next = NULL;
 
     // If the list is empty, set the new node as the first element
     if (*l == NULL) {
         *l = new_node;
         return;
     }
 
     // Traverse to the last node
     struct list *temp = *l;
     while (temp->next != NULL) {
         temp = temp->next;
     }
     temp->next = new_node; // Insert the new node at the end
 }
 
 // Removes the last node from the list
 void remove_end(struct list **l) {
     if (is_empty(*l)) {
         printf("List is empty\n");
         return;
     }
 
     struct list *aux = *l;
     struct list *prev = NULL;
 
     // Traverse to the last node
     while (aux->next != NULL) {
         prev = aux;
         aux = aux->next;
     }
 
     // If the list has only one element
     if (prev == NULL) {
         free(aux);
         *l = NULL;
     } 
     else {
         prev->next = NULL;
         free(aux);
     }
 }
 
 // Displays the elements of the list
 void display(struct list *l) {
     if (is_empty(l)) {
         printf("List is empty\n");
         return;
     }
     struct list *temp = l;  // Start from the first node, not l->next
     printf("List: ");
     while (temp != NULL) {
         printf("%d -> ", temp->data);
         temp = temp->next;
     }
     printf("NULL\n");
 }