/*
Implement functions to insert and remove an element from a circular doubly linked list.
*/

#include <stdio.h>
#include <stdlib.h>

// Defines the structure for a node in the linked list
typedef struct dnode {
    struct dnode *prev;
    int data;
    struct dnode *next;
} Dnode;

// Defines the structure for a list with two pointers in the linked list
typedef struct list {
    Dnode *begin;
    Dnode *end;
} List;

// Function prototypes
void create_list(List **l);
void create_node(Dnode **n, int data);
char list_empty(List *l);
void insert_begin(List *l, int data);
void insert_end(List *l, int data);
void remove_begin(List *l);
void remove_end(List *l);
void print_list(List *l);
void free_list(List *l);

int main() {
    List *l;
    create_list(&l);

    insert_begin(l, 1);
    insert_begin(l, 2);
    insert_end(l, 3);
    insert_end(l, 4);
    print_list(l);

    remove_begin(l);
    remove_end(l);
    print_list(l);

    free_list(l);

    return 0;
}

// Initializes the linked list to be empty
void create_list(List **l) {
    *l = (List *)malloc(sizeof(List));
    (*l)->begin = NULL;
    (*l)->end = NULL;
}

// Creates a new node
void create_node(Dnode **n, int data) {
    *n = (Dnode *)malloc(sizeof(Dnode));
    (*n)->data = data;
    (*n)->prev = NULL;
    (*n)->next = NULL;
}

// Checks if the linked list is empty
char list_empty(List *l) {
    return l->begin == NULL;
}

// Inserts a new element at the beginning of the linked list
void insert_begin(List *l, int data) {
    Dnode *n;
    create_node(&n, data);

    // If the list is empty, the new node is the only node in the list
    if (list_empty(l)) {
        l->begin = n;
        l->end = n;
        n->next = n;
        n->prev = n;
    } 
    else {
        n->next = l->begin; // The new node points to the first node
        n->prev = l->end; // The new node points to the last node
        l->begin->prev = n; // The first node points to the new node
        l->end->next = n; // The last node points to the new node
        l->begin = n; // The new node is now the first node
    }
}

// Inserts a new element at the end of the linked list
void insert_end(List *l, int data) {
    Dnode *n;
    create_node(&n, data);

    // If the list is empty, the new node is the only node in the list
    if (list_empty(l)) {
        l->begin = n;
        l->end = n;
        n->next = n;
        n->prev = n;
    } 
    else {
        n->next = l->begin; // The new node points to the first node
        n->prev = l->end; // The new node points to the last node
        l->begin->prev = n; // The first node points to the new node
        l->end->next = n; // The last node points to the new node
        l->end = n; // The new node is now the last node
    }
}

// Removes the first element of the linked list
void remove_begin(List *l) {
    if (list_empty(l)) {
        printf("The list is empty.\n");
    } 
    else {
        Dnode *n = l->begin; // The first node
        l->begin = n->next; // The second node is now the first node
        l->begin->prev = l->end; // The first node points to the last node
        l->end->next = l->begin; // The last node points to the first node
        free(n); // Frees the memory of the first node
    }
}

// Removes the last element of the linked list
void remove_end(List *l) {
    if (list_empty(l)) {
        printf("The list is empty.\n");
    } 
    else {
        Dnode *n = l->end; // The last node
        l->end = n->prev; // The second to last node is now the last node
        l->begin->prev = l->end; // The first node points to the last node
        l->end->next = l->begin; // The last node points to the first node
        free(n); // Frees the memory of the last node
    }
}

// Prints the linked list
void print_list(List *l) {
    if (list_empty(l)) {
        printf("The list is empty.\n");
    } 
    else {
        Dnode *n = l->begin; // Starts from the first node
        do {
            printf("%d ", n->data); // Prints the data of the node
            n = n->next; // Moves to the next node
        } while (n != l->begin); // Stops when it reaches the first node
        printf("\n");
    }
}

// Frees the memory of the linked list
void free_list(List *l) {
    if (!list_empty(l)) {
        Dnode *n = l->begin; // Starts from the first node
        do {
            Dnode *next = n->next; // Saves the next node
            free(n); // Frees the memory of the current node
            n = next; // Moves to the next node
        } while (n != l->begin); // Stops when it reaches the first node
    }
    free(l); // Frees the memory of the list
}