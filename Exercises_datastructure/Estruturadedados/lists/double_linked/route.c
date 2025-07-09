/**
 * @file route.c
 * @brief Implementation of the functions to route elements in a linked list.
 * 
 * @author João Vitor Sampaio
 * @version 1.0
 * @date 2025-02-25
 */

#include "route.h" // Include the header file with the function prototypes

// clean the entire list
void clean(struct list **l) {
    struct node *aux;
    aux = (*l)->begin; // get the first element of the list

    while (aux != NULL) {
        (*l)->begin = aux->next; // update the head of the list
        free(aux); // free the memory allocated for the node
        aux = (*l)->begin; // move to the next element
    }

    (*l)->end = NULL; // set the end of the list to NULL
}

// search for an element in the list
void search(struct list **l) {
    struct node *aux;
    aux = (*l)->begin; // get the first element of the list

    int n, pos = 0;
    printf("Enter the value to search: ");
    scanf("%d", &n); // read the value to search

    while (aux != NULL) {
        if (aux->data == n) {
            printf("Element found at position %d\n", pos); // print the position of the element
            return;
        }
        aux = aux->next; // move to the next element
        pos++;
    }

    printf("Element not found\n"); // print a message if the element is not found
}

// print the list from the beginning to the end
void print_begin(struct list **l) {
    struct node *aux;
    aux = (*l)->begin; // get the first element of the list

    while (aux != NULL) {
        printf("%d ", aux->data); // print the data of the node
        aux = aux->next; // move to the next element
    }
    printf("\n");
}

// print the list from the end to the beginning
void print_end(struct list **l) {
    struct node *aux;
    aux = (*l)->end; // get the last element of the list

    while (aux != NULL) {
        printf("%d ", aux->data); // print the data of the node
        aux = aux->prev; // move to the previous element
    }
    printf("\n");
}