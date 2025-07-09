/**
 * @file insert.c
 * @brief Implementation of the functions to insert elements in a linked list.
 *
 * @author João Vitor Sampaio
 * @version 1.0
 * @date 2025-02-24
 */

#include "insert.h" // include the header file with the function prototypes

// insert a new element at the beginning of the list
void insert_start(struct knot **l) {
    struct knot *new;
    new = (struct knot *)malloc(sizeof(struct knot)); // allocate memory for the new node
    // check if memory was allocated
    if (new == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    int n;
    printf("Enter the value to insert: ");
    scanf("%d", &n); // read the data to be inserted

    // insert data into the new node
    new->data = n;
    new->next = *l;

    // update the head of the list
    *l = new;
}

// insert a new element in the middle of the list
void insert_middle(struct knot **l) {
    struct knot *new, *aux, *prev;
    new = (struct knot *)malloc(sizeof(struct knot)); // allocate memory for the new node
    // check if memory was allocated
    if (new == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    int n, pos, i = 1;
    printf("Enter the value to insert: ");
    scanf("%d", &n); // read the data to be inserted
    printf("Enter the position to insert: ");
    scanf("%d", &pos); // read the position to insert the data

    // insert data into the new node
    new->data = n;
    new->next = NULL;

    // if the list is empty, the new node becomes the head
    if (is_empty(*l)) {
        *l = new;
    }
    else {
        // traverse to the position to insert the new node
        aux = *l;
        prev = NULL;
        while (!is_empty(aux) && i < pos) {
            prev = aux;
            aux = aux->next;
            i++;
        }
        // insert the new node in the middle
        if (prev != NULL) {
            prev->next = new;
        }
        new->next = aux;
    }
}

// insert a new element at the end of the list
void insert_end(struct knot **l) {
    struct knot *new, *aux;
    new = (struct knot *)malloc(sizeof(struct knot)); // allocate memory for the new node
    // check if memory was allocated
    if (new == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    int n;
    printf("Enter the value to insert: ");
    scanf("%d", &n); // read the data to be inserted

    // insert data into the new node
    new->data = n;
    new->next = NULL;

    // if the list is empty, the new node becomes the head
    if (is_empty(*l)) {
        *l = new;
    }
    else {
        // traverse to the end of the list
        aux = *l;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        // insert the new node at the end
        aux->next = new;
    }
}