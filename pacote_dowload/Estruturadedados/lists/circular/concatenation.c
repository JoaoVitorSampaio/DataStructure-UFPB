/**
 * @file concatenation.c
 * @brief Program to concatenate two circular lists, which can be a linked list, a doubly linked list, or an ordered list.
 * 
 * @author João Vitor Sampaio
 * @version 1.0
 * @date 2025-03-03
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 struct node {
     int data;
     struct node *next;
     struct node *prev; // add prev field for doubly linked list
 };
 
 struct list {
     struct node *begin;
     struct node *end;
 };
 
 // Function to create a linked list
 void create_linked_list(struct node **head) {
     *head = NULL;
 }
 
 // Function to insert an element into a linked list
 void insert_linked_list(struct node **head, int data) {
     struct node *new_node = (struct node *)malloc(sizeof(struct node));
     new_node->data = data;
     if (*head == NULL) {
         *head = new_node;
         new_node->next = *head;
     } else {
         struct node *temp = *head;
         while (temp->next != *head) {
             temp = temp->next;
         }
         temp->next = new_node;
         new_node->next = *head;
     }
 }
 
 // Function to create a double linked list
 void create_double_linked_list(struct list **lst) {
     *lst = (struct list *)malloc(sizeof(struct list));
     (*lst)->begin = NULL;
     (*lst)->end = NULL;
 }
 
 // Function to insert an element into a double linked list
 void insert_double_linked_list(struct list **lst, int data) {
     struct node *new_node = (struct node *)malloc(sizeof(struct node));
     new_node->data = data;
     new_node->next = NULL;
     if ((*lst)->begin == NULL) {
         (*lst)->begin = new_node;
         (*lst)->end = new_node;
         new_node->prev = NULL;
     } else {
         (*lst)->end->next = new_node;
         new_node->prev = (*lst)->end;
         (*lst)->end = new_node;
     }
 }
 
 // Function to print a linked list
 void print_linked_list(struct node *head) {
     if (head == NULL) return;
     struct node *temp = head;
     do {
         printf("%d ", temp->data);
         temp = temp->next;
     } while (temp != head);
     printf("\n");
 }
 
 // Function to print a double linked list
 void print_double_linked_list(struct list *lst) {
     struct node *temp = lst->begin;
     while (temp != NULL) {
         printf("%d ", temp->data);
         temp = temp->next;
     }
     printf("\n");
 }
 
 // concatenates two linked lists
 void concatenate_linked_lists(struct node **l1, struct node **l2) {
     struct node *aux = *l1; // creates an auxiliary pointer to the first list
     while (aux->next != *l1) { // goes to the last node of the first list
         aux = aux->next;
     }
     aux->next = (*l2)->next; // connects the last node of the first list to the first node of the second list
     (*l2)->next = *l1; // connects the last node of the second list to the first node of the first list
     *l1 = *l2; // sets the head pointer to the head pointer of the second list
 }
 
 // concatenates two double linked lists
 void concatenate_double_linked_lists(struct list **l1, struct list **l2) {
     if ((*l1)->begin == NULL) { // if the first list is empty
         *l1 = *l2; // sets the head pointer to the head pointer of the second list
     } 
     else if ((*l2)->begin != NULL) { // if the second list is not empty
         (*l1)->end->next = (*l2)->begin; // connects the last node of the first list to the first node of the second list
         (*l2)->begin->prev = (*l1)->end; // connects the first node of the second list to the last node of the first list
         (*l1)->end = (*l2)->end; // sets the end pointer to the end pointer of the second list
     }
     free(*l2); // frees the memory allocated for the second list
 }
 
 // Concatenates two ordered circular linked lists
 void concatenate_ordered_lists(struct node **l1, struct node **l2) {
     if (*l1 == NULL) { // If the first list is empty
         *l1 = *l2;     // Set head to second list
         return;
     }
     if (*l2 == NULL) { // If the second list is empty
         return;
     }
 
     struct node *aux2 = *l2;
     struct node *next2;
     struct node *head2 = *l2; // Save the start of l2
 
     do {
         next2 = aux2->next;
 
         // Insert aux2 into the correct position in l1
         if (aux2->data < (*l1)->data) { // Insert at the beginning
             struct node *last = *l1;
             while (last->next != *l1) {
                 last = last->next;
             }
             aux2->next = *l1;
             last->next = aux2;
             *l1 = aux2;
         } else { // Insert in the middle or end
             struct node *current = *l1;
             while (current->next != *l1 && current->next->data < aux2->data) {
                 current = current->next;
             }
             aux2->next = current->next;
             current->next = aux2;
         }
 
         aux2 = next2;
     } while (aux2 != head2);
 }
 
 int main() {
     struct node *l1, *l2; // declares two linked lists
     struct list *l3, *l4; // declares two double linked lists
 
     create_linked_list(&l1); // creates the first linked list
     create_linked_list(&l2); // creates the second linked list
     create_double_linked_list(&l3); // creates the first double linked list
     create_double_linked_list(&l4); // creates the second double linked list
 
     // inserts elements into the first linked list
     insert_linked_list(&l1, 1);
     insert_linked_list(&l1, 3);
     insert_linked_list(&l1, 5);
     insert_linked_list(&l1, 7);
     insert_linked_list(&l1, 9);
 
     // inserts elements into the second linked list
     insert_linked_list(&l2, 2);
     insert_linked_list(&l2, 4);
     insert_linked_list(&l2, 6);
     insert_linked_list(&l2, 8);
     insert_linked_list(&l2, 10);
 
     // inserts elements into the first double linked list
     insert_double_linked_list(&l3, 1);
     insert_double_linked_list(&l3, 3);
     insert_double_linked_list(&l3, 5);
     insert_double_linked_list(&l3, 7);
     insert_double_linked_list(&l3, 9);
 
     // inserts elements into the second double linked list
     insert_double_linked_list(&l4, 2);
     insert_double_linked_list(&l4, 4);
     insert_double_linked_list(&l4, 6);
     insert_double_linked_list(&l4, 8);
     insert_double_linked_list(&l4, 10);
 
     // concatenates the two linked lists
     concatenate_linked_lists(&l1, &l2);
 
     // concatenates the two double linked lists
     concatenate_double_linked_lists(&l3, &l4);
 
     // prints the concatenated linked list
     print_linked_list(l1);
 
     // prints the concatenated double linked list
     print_double_linked_list(l3);
 
     // declares two ordered lists
     struct node *l5, *l6;
 
     create_linked_list(&l5); // creates the first ordered list
     create_linked_list(&l6); // creates the second ordered list
 
     // inserts elements into the first ordered list
     insert_linked_list(&l5, 1);
     insert_linked_list(&l5, 3);
     insert_linked_list(&l5, 5);
     insert_linked_list(&l5, 7);
     insert_linked_list(&l5, 9);
 
     // inserts elements into the second ordered list
     insert_linked_list(&l6, 2);
     insert_linked_list(&l6, 4);
     insert_linked_list(&l6, 6);
     insert_linked_list(&l6, 8);
     insert_linked_list(&l6, 10);
 
     // concatenates the two ordered lists
     concatenate_ordered_lists(&l5, &l6);
 
     // prints the concatenated ordered list
     print_linked_list(l5);
 
     return 0;
 }