#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int greater(struct list *l, int n) {
    int count = 0;
    struct list *node = l;  // Start from the head node
    while (node != NULL) {
        if (node->data > n) {
            count++;
        }
        node = node->next;
    }
    return count;
}

int main() {
    struct list *l = NULL;  // Initialize head pointer
    create(&l);  // Ensure create() properly initializes l

    int choice;
    while (1) {
        printf("\n1. Insert\n");
        printf("2. Remove\n");
        printf("3. Display\n");
        printf("4. Greater\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_end(&l);  // Pass pointer to pointer if modifying head
                break;
            case 2:
                remove_end(&l);  // Pass pointer to pointer if modifying head
                break;
            case 3:
                display(l);
                break;
            case 4: {
                int n;
                printf("Enter the value of n: ");
                scanf("%d", &n);
                printf("Number of nodes with values greater than %d: %d\n", n, greater(l, n));
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