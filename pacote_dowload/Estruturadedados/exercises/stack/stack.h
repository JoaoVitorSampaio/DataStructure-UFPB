/*
Consider the existence of an abstract type Stack of real numbers, whose interface is defined in the file stack.h as follows:

typedef struct stack Stack;
Stack* stack_create(void);
void stack_push(Stack* p, float v);
float stack_pop(Stack* p);
int stack_empty(Stack* p);
void stack_release(Stack* p);

Without knowing the internal representation of this abstract type and having only the functions declared in the interface file:

⚫ a) Implement a function that receives a stack as a parameter and returns the value stored at its top, restoring the contents of the stack. 
This function must obey the prototype:
float top(Stack* p);

⚫ b) Implement a function that receives two stacks, p1 and p2, and passes all the elements of stack p2 to the top of stack p1. 
Note that, at the end of this function, stack p2 will be empty, and stack pl will contain all the elements of both stacks. 
This function must follow the prototype:
void concatenate_stacks(Stack* p1, Stack* p2);
This function can be implemented more easily using a recursive solution or another auxiliary stack variable to transfer the elements between the two stacks.

⚫ c) Implement a function that receives a stack as a parameter and returns a copy of that stack as a result. 
This function must follow the prototype:
Stack copy_stack(Stack* p);
At the end of the copy_stack function, the stack p received as a parameter must have its original contents. 
This function can be implemented more easily with a recursive solution or using another auxiliary stack variable.
*/

#ifndef STACK_H // checks if the header has already been included
#define STACK_H // if not, define the header

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

/**
 * @brief Defines the structure for a node in the stack.
 * @param data The data stored in the node.
 * @param next A pointer to the next node. 
 */
typedef struct stack Stack;

/**
 * @brief Initializes the stack to be empty.
 * @return Stack* A pointer to the head of the stack.
 */
Stack *stack_create(void);

/**
 * @brief Pushes a value to the stack.
 * @param p A pointer to the head of the stack.
 * @param v The value to be pushed.
 * @return void
 */
void stack_push(Stack *p, float v);

/**
 * @brief Pops a value from the stack.
 * @param p A pointer to the head of the stack.
 * @return float The value popped.
 */
float stack_pop(Stack *p);

/**
 * @brief Checks if the stack is empty.
 * @param p A pointer to the head of the stack.
 * @return int 1 if the stack is empty, 0 otherwise.
 */
int stack_empty(Stack *p);

/**
 * @brief Releases the stack.
 * @param p A pointer to the head of the stack.
 * @return void
 */
void stack_release(Stack *p);

/**
 * @brief Returns the value stored at the top of the stack.
 * @param p A pointer to the head of the stack.
 * @return float The value stored at the top of the stack.
 */
float top(Stack *p);

/**
 * @brief Passes all the elements of stack p2 to the top of stack p1.
 * @param p1 A pointer to the head of the stack.
 * @param p2 A pointer to the head of the stack.
 * @return void
 */
void concatenate_stacks(Stack *p1, Stack *p2);

/**
 * @brief Returns a copy of the stack.
 * @param p A pointer to the head of the stack.
 * @return Stack* A pointer to the head of the copied stack.
 */
Stack *stack_copy(Stack *p);

/**
 * @brief Prints the stack.
 * @param p A pointer to the head of the stack.
 * @return void
 */
void stack_print(Stack *p);

#endif // end of the header guard