/**
* @file route.c
 * @brief Implementation of the functions to manipulate a linked list.
 *
 * @author João Vitor Sampaio
 * @version 1.0
 * @date 2025-02-24
 */

#include "route.h" // include the header file with the function prototypes

// clean the entire list
void clean(struct knot **l) {
    struct knot *aux;
    while (!is_empty(*l)) {
        aux = *l;
        *l = (*l)->next;
        free(aux); // free memory of each node
    }
}

// search for an element in the list
void search(struct knot *l) {
    struct knot *aux = l;
    int n;
    printf("Enter the value to search: ");
    scanf("%d", &n); // read the data to be searched

    // search for the element
    while (!is_empty(aux) && aux->data != n) {
        aux = aux->next;
    }

    // check if the element was found
    if (is_empty(aux)) {
        printf("Element not found\n");
    }
    else {
        printf("Element found\n");
    }
}

// print all elements in the list
void print(struct knot *l) {
    struct knot *aux = l;
    printf("\nList: ");
    while (!is_empty(aux)) {
        printf("%d ", aux->data); // print data of each node
        aux = aux->next;
    }
    printf("\n");
}