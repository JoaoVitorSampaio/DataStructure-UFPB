/*
Implement a function that returns the length of a linked list, that is, that calculates the number of nodes in a list. 
This function must conform to the following prototype:
int length(List* l);
*/

#include "list.h"

int length(struct list *l) {
    int count = 0;
    struct list *temp = l->next; // Skip the dummy node
    // Traverse the list and count the number of nodes
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    struct list *l;
    create(&l); // Initialize the list

    int choice;
    while (1) {
        printf("1. Insert at the end\n");
        printf("2. Remove from the end\n");
        printf("3. Display\n");
        printf("4. Length\n");
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
                printf("Length: %d\n", length(l));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
