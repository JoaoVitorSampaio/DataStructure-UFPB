/*
Consider lists of integer values ​​and implement a function that receives as a parameter a linked list and an integer value n and divides the list in two, so that the second list starts at the first node right after the first occurrence of n in the original list. 
The following figure illustrates this separation:
This function must follow the prototype:
List *separate(List *l, int n);
The function should return a pointer to the second subdivision of the original list, while l should continue to point to the first element of the first subdivision of the list.
*/

#include "list.h"

struct list *separate(struct list *l, int n) {
    if (is_empty(l)) { // if the list is empty
        return NULL; // returns NULL
    }
    struct list *aux = l; // creates an auxiliary pointer to the list
    while (aux->next != NULL && aux->data != n) {
        aux = aux->next; // goes to the first occurrence of n in the list
    }
    if (aux->data == n) { // if the value was found
        struct list *new_list = aux->next; // creates a new list starting from the next node
        aux->next = NULL; // disconnects the original list from the new list
        return new_list; // returns the new list
    }
    return NULL; // returns NULL if the value was not found
}

int main() {
    struct list *l;
    create(&l);

    int choice;
    while (1) {
        printf("\n1. Insert\n");
        printf("2. Remove\n");
        printf("3. Display\n");
        printf("4. Separate\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_end(&l);
                break;
            case 2:
                remove_end(&l);
                break;
            case 3:
                display(l);
                break;
            case 4: {
                int n;
                printf("Enter the value of n: ");
                scanf("%d", &n);
                struct list *l2 = separate(l, n);
                display(l);
                display(l2);
                break;
            }
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;    
}