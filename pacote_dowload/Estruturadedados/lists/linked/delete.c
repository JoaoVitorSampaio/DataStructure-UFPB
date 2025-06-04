/**
* @file delete.c
 * @brief Implementation of the functions to delete elements from a linked list.
 *
 * @author João Vitor Sampaio
 * @version 1.0
 * @date 2025-02-24
 */

#include "delete.h" // include the header file with the function prototypes

// delete an element from the list at the beginning of the list
void delete_start(struct knot **l) {
    if (is_empty(*l)) {
        printf("List is empty\n");
        return;
    }

    struct knot *aux = *l;
    *l = aux->next;

    // free memory of the deleted node
    free(aux);
}

// delete an element from the list in the middle of the list
void delete_middle(struct knot **l) {
    if(is_empty(*l)) {
        printf("List is empty\n");
        return;
    }

    struct knot *aux = *l, *prev = NULL;
    int pos, i = 1;
    printf("Enter the position to delete: ");
    scanf("%d", &pos); // read the position to delete the data

    // traverse to the position to delete the node
    while (!is_empty(aux) && i < pos) {
        prev = aux;
        aux = aux->next;
        i++;
    }

    // check if the element was found
    if(is_empty(aux)) {
        printf("Position not found\n");
        return;
    }

    // check if the element is the first in the list
    if (prev == NULL) {
        *l =  aux->next;
    }
    else {
        prev->next = aux->next;
    }

    free(aux);
    }

// delete an element from the list at the end of the list
void delete_end(struct knot **l) {
    if (is_empty(*l)) {
        printf("List is empty\n");
        return;
    }

    struct knot *aux = *l, *prev = NULL;

    // traverse to the end of the list
    while (aux->next != NULL) {
        prev = aux;
        aux =  aux->next;
    }

    // check if the element is the first in the list
    if (prev == NULL) {
        *l = NULL;
    }
    else {
        prev->next = NULL;
    }

    // free memory of the deleted node
    free(aux);
}