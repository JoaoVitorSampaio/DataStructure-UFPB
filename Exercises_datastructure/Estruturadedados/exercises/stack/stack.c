/**
 * @file stack.c
 * @brief This file contains the implementation of the stack functions.
 * 
 * @author João Vitor Sampaio
 * @date 2025-03-16
 * @version 1.0
 */

 #include "stack.h" // for the stack structure

 // Define the stack structure
 typedef struct stack {
     float data;
     struct stack *next;
 } Stack;
 
 // Create a new stack
 Stack *stack_create(void) {
     Stack *p = (Stack *)malloc(sizeof(Stack)); // Allocate memory for the stack
     p->next = NULL; // Initialize the stack
     return p; // Return the stack
 }
 
 // Push a value to the stack
 void stack_push(Stack *p, float v) {
     Stack *new_node = (Stack *)malloc(sizeof(Stack)); // Allocate memory for the new node
     new_node->data = v; // Set the value of the new node
     new_node->next = p->next; // Set the next pointer of the new node
     p->next = new_node; // Set the next pointer of the stack
 }
 
 // Pop a value from the stack
 float stack_pop(Stack *p) {
     Stack *temp = p->next; // Create a temporary pointer to the top of the stack
     float v = temp->data; // Get the value of the top node
     p->next = temp->next; // Set the next pointer of the stack
     free(temp); // Free the memory of the top node
     return v; // Return the value
 }
 
 // Check if the stack is empty
 int stack_empty(Stack *p) {
     return p->next == NULL; // Return 1 if the stack is empty, 0 otherwise
 }
 
 // Release the stack
 void stack_release(Stack *p) {
     while (!stack_empty(p)) { // While the stack is not empty
         stack_pop(p); // Pop a value from the stack
     }
     free(p); // Free the memory of the stack
 }
 
 // Return the value stored at the top of the stack
 float top(Stack *p) {
     return p->next->data; // Return the value of the top node
 }
 
 // Pass all the elements of stack p2 to the top of stack p1
 void concatenate_stacks(Stack *p1, Stack *p2) {
     Stack *temp = stack_create(); // Create a temporary stack to maintain the correct order
 
     // Transfer elements from p2 to the temporary stack
     while (!stack_empty(p2)) {
         stack_push(temp, stack_pop(p2)); // Pop from p2 and push onto temp
     }
 
     // Now transfer elements from the temporary stack to p1
     while (!stack_empty(temp)) {
         stack_push(p1, stack_pop(temp)); // Pop from temp and push onto p1
     }
 
     stack_release(temp); // Free the memory of the temporary stack
     stack_release(p2);   // Free the memory of p2 after copying its elements
 }
 
 // Copy the elements of stack
 Stack *stack_copy(Stack *p) {
     Stack *new_stack = stack_create(); // Create a new stack
     Stack *temp = p->next; // Create a temporary pointer to the top of the stack
     while (temp != NULL) { // While there are nodes in the stack
         stack_push(new_stack, temp->data); // Push the value of the node to the new stack
         temp = temp->next; // Move to the next node
     }
     return new_stack; // Return the new stack
 }
 
 // Print the stack
 void stack_print(Stack *p) {
     Stack *temp = p->next; // Create a temporary pointer to the top of the stack
     printf("Stack: "); // Print the stack
     while (temp != NULL) { // While there are nodes in the stack
         printf("%f ", temp->data); // Print the value of the node
         temp = temp->next; // Move to the next node
     }
     printf("\n"); // Print a newline character
 }