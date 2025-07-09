/*
Implement a function that returns a pointer to the last node of a linked list. 
This function must conform to the following prototype:
List* last(List* l);
*/

#include "list.h"

struct list *last(struct list *l) {
    // If the list is empty, return NULL
    if (is_empty(l)) {
        return NULL;
    }

    // Traverse the list until the last node is reached
    while (l->next != NULL) {
        l = l->next;
    }

    return l; // Return the last node
}

int main() {
    struct list *l;
    create(&l);

    int choice;
    while (1) {
        printf("\n1. Insert\n");
        printf("2. Remove\n");
        printf("3. Display\n");
        printf("4. Last\n");
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
            case 4: 
                printf("Last node: %d\n", last(l)->data);    
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;    
}