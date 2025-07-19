/*
Implements expression validation using stack.
The program reads a postfix expression and checks if the expression is valid or not.
The expression is valid if the brackets are balanced.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct list {
    char data[MAX];
    int ctr;
};

// function prototypes
void create(struct list **);
int is_empty(struct list *);
int is_full(struct list *);
void push(struct list *, char);
void pop(struct list *);

// creates a new stack
void create(struct list **l) {
    *l = (struct list *)malloc(sizeof(struct list));
    if (*l == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    (*l)->ctr = 0;
}

// checks if the stack is empty
int is_empty(struct list *l) {
    return l->ctr == 0;
}

// checks if the stack is full
int is_full(struct list *l) {
    return l->ctr == MAX;
}

// pushes a new element to the stack
void push(struct list *l, char data) {
    if (is_full(l)) {
        printf("The stack is full.\n");
        return;
    }
    l->data[l->ctr] = data;
    l->ctr++;
}

// pops an element from the stack
void pop(struct list *l) {
    if (is_empty(l)) {
        printf("The stack is empty.\n");
        return;
    }
    l->ctr--;
}

int main() {
    struct list *l;
    create(&l);
    char expression[MAX];
    printf("Enter the postfix expression: ");
    fgets(expression, MAX, stdin);
    // remove newline character from the end of the expression if present
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }
    // special characters
    char vector[] = {' ', '.', ',', ';', ':', '?', '!', '-', '+', '*', '/', '%', '^', '&', '|', '<', '>', '=', '~', '`', '@', '#', '$', '_', '\\', '"', '\'', '\0'};
    // iterate through the expression
    for (int i=0; i<strlen(expression); i++) {
        // skip alphabets and numbers
        if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z') || (expression[i] >= '0' && expression[i] <= '9')) {
            continue;
        }
        // skip special characters

        for (int j=0; j<strlen(vector); j++) {
            if (expression[i] == vector[j]) {
                continue;
            }
        }
        // push the opening brackets to the stack
        if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(') {
            push(l, expression[i]);
        } 
        // pop the closing brackets from the stack
        else {
            if (is_empty(l)) {
                printf("The expression is invalid.\n");
                free(l);
                return 0;
            }
            char top = l->data[l->ctr-1];
            if (expression[i] == '}' && top == '{') {
                pop(l);
            }
            else if (expression[i] == ']' && top == '[') {
                pop(l);
            }
            else if (expression[i] == ')' && top == '(') {
                pop(l);
            }
            else {
                break;
            }
        }
    }
    // if the stack is empty, the expression is valid
    if (is_empty(l)) {
        printf("The expression is valid.\n");        
    }
    else {
        printf("The expression is invalid.\n");
    }
    free(l);

    return 0;
}