/**
 * @file route.c
 * @brief Queue route implementation
 * 
 * @author João Vitor Sampaio
 * @version 1.1
 * @date 2025-03-18
 */

 #include "route.h" 

 // list by vector
 // consult the element at the beginning of the list
 int consult_vector_list(struct vector *l) {
     return l->data[l->start];
 }
 
 // clean the entire list
 void clean_vector_list(struct vector *l) {
     free(l);
 }
 
 // print all elements in the list
 void print_vector_list(struct vector *l) {
     for (int i = 0; i < l->n; i++) {
         printf("%d ", l->data[(l->start + i) % SIZE]);
     }
     printf("\n");
 }
 
 
 // list by linked list
 // consult the element at the beginning of the list
 int consult_linked_list(struct queue *l) {
     return l->head->data;
 }
 
 // clean the entire list
 void clean_linked_list(struct queue **l) {
     struct node *aux = (*l)->head; // aux pointer to the head of the queue
     while (aux != NULL) { // while the aux pointer is not NULL
         struct node *temp = aux->next; // temp pointer to the next node
         free(aux); // free the current node
         aux = temp; // aux pointer to the next node
     }
     free(l); // free the queue
 }
 
 // print all elements in the list from the beginning to the end
 void print_linked_list(struct queue *l) {
     struct node *aux; // aux pointer to the head of the queue
     for (aux = l->head; aux != NULL; aux = aux->next) {
         printf("%d ", aux->data); // print the data of the current node
     }
     printf("\n");
 }
 
 
 // list by doubly linked list
 // consult the element at the beginning of the list
 int consult_doubly_linked_list(struct dqueue *l) {
     return l->head->data;
 }
 
 // clean the entire list
 void clean_doubly_linked_list(struct dqueue **l) {
     struct dnode *aux = (*l)->head; // aux pointer to the head of the queue
     while (aux != NULL) { // while the aux pointer is not NULL
         struct dnode *temp = aux->next; // temp pointer to the next node
         free(aux); // free the current node
         aux = temp; // aux pointer to the next node
     }
     free(l); // free the queue
 }
 
 // print all elements in the list from the beginning to the end
 void print_doubly_linked_list(struct dqueue *l) {
     struct dnode *aux; // aux pointer to the head of the queue
     for (aux = l->head; aux != NULL; aux = aux->next) {
         printf("%d ", aux->data); // print the data of the current node
     }
     printf("\n");
 }