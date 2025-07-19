/*
Implement a function that builds a new list by merging the nodes from two other lists passed as parameters. 
This function should return the resulting list, as illustrated below:
This function must conform to the prototype:
List *merge(List *l1, List *l2)
*/

#include "list.h"

typedef struct list List;

// Inserts a new node with the given value after the given node
// Inserts a new node at the end of the list
void insert(List **list, int value) {
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

List *merge(List *l1, List *l2) {
    List *new_list = NULL; // Initialize the new list
    List **tail = &new_list; // Double pointer to track the last node

    List *cur1 = l1; // Pointer to traverse l1
    List *cur2 = l2; // Pointer to traverse l2

    while (cur1 != NULL || cur2 != NULL) {  
        if (cur1 != NULL) {  // If there are still elements in l1
            insert(tail, cur1->data);
            cur1 = cur1->next;
            tail = &((*tail)->next); // Update the tail pointer
        }
        if (cur2 != NULL) {  // If there are still elements in l2
            insert(tail, cur2->data);
            cur2 = cur2->next;
            tail = &((*tail)->next); // Update the tail pointer
        }
    }

    return new_list; // Return the merged list
}

int main() {
    List *l1, *l2, *l3;
    create(&l1);
    create(&l2);

    insert(&l1, 1);
    insert(&l1, 2);
    insert(&l1, 3);

    insert(&l2, 4);
    insert(&l2, 5);
    insert(&l2, 6);

    l3 = merge(l1, l2);

    display(l3);

    return 0;
}