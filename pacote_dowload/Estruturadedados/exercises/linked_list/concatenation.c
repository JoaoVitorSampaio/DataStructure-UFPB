#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list *concatenates(struct list *l1, struct list *l2) {
    if (l1 == NULL) return l2; // If first list is empty, return second list
    if (l2 == NULL) return l1; // If second list is empty, return first list

    struct list *aux = l1;
    while (aux->next != NULL) {
        aux = aux->next; // Traverse to the last node of first list
    }
    aux->next = l2; // Link last node of first list to first node of second list

    return l1; // Return concatenated list
}

int main() {
    struct list *l = NULL;  // Ensure head is initialized
    create(&l);

    int choice;
    while (1) {
        printf("\n1. Insert\n");
        printf("2. Remove\n");
        printf("3. Display\n");
        printf("4. Concatenates\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_end(&l);  // ✅ Pass pointer to pointer
                break;
            case 2:
                remove_end(&l);  // ✅ Pass pointer to pointer
                break;
            case 3:
                display(l);
                break;
            case 4: {
                struct list *l2 = NULL;  // Initialize new list
                create(&l2);

                printf("Inserting elements into the second list:\n");
                insert_end(&l2);
                insert_end(&l2);

                l = concatenates(l, l2); // Concatenate lists and update head

                printf("Concatenated list:\n");
                display(l);
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
