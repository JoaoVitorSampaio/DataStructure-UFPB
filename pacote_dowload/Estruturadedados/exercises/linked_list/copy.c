/*
Consider lists that store strings of characters and implement a function to create a copy of a linked list. 
This function must obey the following prototype:
List *copy(List *l);
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of the structure of a list node
typedef struct lst {
    char data;
    struct lst *next;
} List;

// Function to create an empty list
void create_list(List **list) {
    *list = NULL;
}

// Inserts a new node with the given value after the given node
// Inserts a new node at the end of the list
void insert(List **list, char value) {
    List *new_node = (List *)malloc(sizeof(List));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    // If the list is empty, initialize it with the new node
    if (*list == NULL) {
        *list = new_node;
        return;
    }

    // Traverse to the last node
    List *temp = *list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// function to copy a list
List *copy(List *l) {
    List *new_list = NULL; // new list to store the copy
    List *aux = l; // auxiliary pointer to go through the list

    // go through the list
    while (aux != NULL) {
        insert(&new_list, aux->data); // insert the element in the new list
        aux = aux->next; // go to the next element
    }

    return new_list; // return the new list
}

int main() {
    List *l; // lists to be compared

    // create the lists
    create_list(&l);

    // insert elements in the list
    insert(&l, 'a');
    insert(&l, 'b');
    insert(&l, 'c');
    insert(&l, 'd');
    insert(&l, 'e');

    // copy the list
    List *l2 = copy(l);

    // display the original list
    printf("Original list: ");
    List *aux = l;
    while (aux != NULL) {
        printf("%c ", aux->data);
        aux = aux->next;
    }

    // display the copied list
    printf("\nCopied list: ");
    aux = l2;
    while (aux != NULL) {
        printf("%c ", aux->data);
        aux = aux->next;
    }

    return 0; 
}