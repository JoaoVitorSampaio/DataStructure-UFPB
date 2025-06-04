#include "list.h"

typedef struct list List;

// Function to reverse the linked list
List *reverse(List *l) {
    List *prev = NULL;    // Pointer to the previous node (initially NULL)
    List *current = l;    // Pointer to the current node (starts at the head)
    List *next = NULL;    // Pointer to the next node (will be used to traverse)

    // Iterate through the list and reverse the links
    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev one step forward
        current = next;       // Move current one step forward
    }

    return prev; // Return the new head of the list (previously the last node)
}

int main() {
    List *l; // Pointer to the head of the linked list
    create(&l); // Initialize the linked list (assumed to be defined in "list.h")

    int choice;
    while (1) { // Infinite loop for menu-driven execution
        printf("\n1. Insert\n");
        printf("2. Remove\n");
        printf("3. Display\n");
        printf("4. Reverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_end(&l); // Function to insert a node at the end of the list
                break;
            case 2:
                remove_end(&l); // Function to remove a node from the end of the list
                break;
            case 3:
                display(l); // Function to display the list
                break;
            case 4:
                l = reverse(l); // Reverse the linked list
                display(l); // Display the reversed list
                break;
            case 5:
                exit(0); // Exit the program
            default:
                printf("Invalid choice\n"); // Handle invalid input
        }
    }

    return 0; // Indicate successful execution
}
