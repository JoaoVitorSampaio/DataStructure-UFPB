#include "stack.h" // Ensure this file contains function declarations

int main() {
    Stack *p = stack_create(); // Create a new stack
    int choice; // Variable to store the user's choice

    while (1) { // Infinite loop until the user chooses to exit
        // Display menu
        printf("\n===== MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Empty\n");
        printf("4. Release\n");
        printf("5. Top\n");
        printf("6. Concatenate\n");
        printf("7. Copy\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) { // Validate user input
            printf("Invalid input. Please enter a number between 1 and 8.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1: { // Push operation
                float v;
                printf("Enter the value to push: ");
                if (scanf("%f", &v) != 1) {
                    printf("Invalid input. Try again.\n");
                    while (getchar() != '\n');
                    continue;
                }
                stack_push(p, v);
                break;
            }
            case 2: { // Pop operation
                if (!stack_empty(p)) {
                    printf("Popped value: %f\n", stack_pop(p));
                } 
                else {
                    printf("Stack is empty\n");
                }
                break;
            }
            case 3: { // Check if the stack is empty
                printf("Stack is %s\n", stack_empty(p) ? "empty" : "not empty");
                break;
            }
            case 4: { // Release stack memory
                stack_release(p);
                printf("Stack released.\n");
                p = stack_create(); // Ensure new stack is allocated
                break;
            }
            case 5: { // Get the top element
                if (!stack_empty(p)) {
                    printf("Top value: %f\n", top(p)); // Use stack_top instead of top
                } 
                else {
                    printf("Stack is empty\n");
                }
                break;
            }
            case 6: { // Concatenate two stacks
                Stack *p2 = stack_create();
                int n;
                printf("Enter the number of elements to push into the second stack: ");
                if (scanf("%d", &n) != 1 || n < 1) {
                    printf("Invalid input. Try again.\n");
                    while (getchar() != '\n');
                    stack_release(p2);
                    continue;
                }
                for (int i = 0; i < n; i++) {
                    float v;
                    printf("Enter value %d: ", i + 1);
                    if (scanf("%f", &v) != 1) {
                        printf("Invalid input. Aborting concatenation.\n");
                        while (getchar() != '\n');
                        stack_release(p2);
                        break;
                    }
                    stack_push(p2, v);
                }
                concatenate_stacks(p, p2); // Concatenate the two stacks
                printf("Stacks concatenated.\n");
                // stack_release(p2); // Free memory of the second stack after concatenation
                break;
            }
            case 7: { // Copy the stack
                Stack *new_stack = stack_copy(p);
                if (new_stack) {
                    printf("Copied stack: ");
                    stack_print(new_stack);
                    stack_release(new_stack); // Free memory of the copied stack to avoid leaks
                } 
                else {
                    printf("Failed to copy stack.\n");
                }
                break;
            }
            case 8: { // Exit the program
                stack_release(p); // Free stack memory before exiting
                printf("Exiting program...\n");
                return 0;
            }
            default:
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }
    }

    return 0;
}