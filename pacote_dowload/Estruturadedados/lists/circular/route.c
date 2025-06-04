/**
 * @file route.c
 * @brief Circular linked list route implementation
 * 
 * @author João Vitor Sampaio
 * @version 2.0
 * @date 2025-03-01
 */

 #include "route.h" // for circular linked list

 // circular list by vector
 // clean the entire list
 void clean_vector_list(struct vector *l) {
     l->head = 0; // sets the head to the beginning
     l->tail = 0; // sets the tail to the beginning
     l->size = 0; // sets the size to zero
 }
 
 // search for an element in the list
 void search_vector_list(struct vector *l) {
     int d;
     printf("Data: ");
     scanf("%d", &d);
 
     int i;
     for (i = 0; i < l->size; i++) {
         if (l->data[i] == d) {
             printf("Element found at position %d.\n", i);
             return;
         }
     }
     printf("Element not found.\n");
 }
 
 // print all elements in the list
 void print_vector_list(struct vector *l) {
     int i;
     for (i = 0; i < l->size; i++) {
         printf("%d ", l->data[i]);
     }
     printf("\n");
 }
 
 
 // circular list by linked list
 // clean the entire list
 void clean_linked_list(struct node **l) {
     struct node *aux;
     aux = (*l)->next; // start from the beginning of the list
 
     while (aux != *l) {
         (*l)->next = aux->next; // update the head of the list
         free(aux); // free the memory allocated for the node
         aux = (*l)->next; // move to the next node
     }
 
     (*l)->next = NULL; // update the end pointer
 }
 
 // search for an element in the list
 void search_linked_list(struct node **l) {
     int d;
     printf("Data: ");
     scanf("%d", &d);
 
     struct node *aux;
     aux = (*l)->next; // start from the beginning of the list
 
     int pos = 0;
     while (aux != *l) {
         if (aux->data == d) {
             printf("Element found at position %d.\n", pos);
             return;
         }
         aux = aux->next; // move to the next node
         pos++;
     }
 
     printf("Element not found.\n");
 }
 
 // print all elements in the list from the beginning to the end
 void print_linked_list(struct node **l) {
     struct node *aux;
     aux = (*l)->next; // start from the beginning of the list
 
     while (aux != *l) {
         printf("%d ", aux->data); // print the data in the node
         aux = aux->next; // move to the next node
     }
 
     printf("\n");
 }
 
 
 // circular list by double linked list
 // clean the entire list
 void clean_double_linked_list(struct list **l) {
     struct dnode *aux;
     aux = (*l)->begin; // start from the beginning of the list
 
     while (aux != NULL) {
         (*l)->begin = aux->next; // update the head of the list
         free(aux); // free the memory allocated for the node
         aux = (*l)->begin; // move to the next node
     }
 
     (*l)->end = NULL; // update the end pointer
 }
 
 // search for an element in the list
 void search_double_linked_list(struct list **l) {
     int d;
     printf("Data: ");
     scanf("%d", &d);
 
     struct dnode *aux;
     aux = (*l)->begin; // start from the beginning of the list
 
     int pos = 0;
     while (aux != NULL) {
         if (aux->data == d) {
             printf("Element found at position %d.\n", pos);
             return;
         }
         aux = aux->next; // move to the next node
         pos++;
     }
 
     printf("Element not found.\n");
 }
 
 // print all elements in the list from the beginning to the end
 void print1_double_linked_list(struct list **l) {
     struct dnode *aux;
     aux = (*l)->begin; // start from the beginning of the list
 
     while (aux != NULL) {
         printf("%d ", aux->data); // print the data in the node
         aux = aux->next; // move to the next node
     }
 
     printf("\n");
 }
 
 // print all elements in the list from the end to the beginning
 void print2_double_linked_list(struct list **l) {
     struct dnode *aux;
     aux = (*l)->end; // start from the end of the list
 
     while (aux != NULL) {
         printf("%d ", aux->data); // print the data in the node
         aux = aux->prev; // move to the previous node
     }
 
     printf("\n");
 }