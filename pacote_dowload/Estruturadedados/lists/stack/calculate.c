#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Para usar isdigit()

#define MAX 100

struct stack {
    int data[MAX]; // Armazena inteiros
    int ctr;
};

// Funções para manipulação da pilha
void create(struct stack *l);
int is_empty(struct stack *l);
int is_full(struct stack *l);
void push(struct stack *l, int data);
int pop(struct stack *l);

void create(struct stack *l) {
    l->ctr = 0; // Inicializa a pilha
}

int is_empty(struct stack *l) {
    return l->ctr == 0;
}

int is_full(struct stack *l) {
    return l->ctr == MAX;
}

void push(struct stack *l, int data) {
    if (is_full(l)) {
        printf("The stack is full.\n");
        return;
    }
    l->data[l->ctr++] = data; // Insere o valor e incrementa ctr
}

int pop(struct stack *l) {
    if (is_empty(l)) {
        printf("The stack is empty.\n");
        exit(1); // Termina o programa caso a pilha esteja vazia
    }
    return l->data[--l->ctr]; // Decrementa ctr e retorna o elemento removido
}

// Função principal para cálculo de expressão pós-fixa
int main() {
    struct stack l;
    create(&l); // Inicializa a pilha

    char expression[MAX];
    printf("Enter the postfix expression: ");
    fgets(expression, MAX, stdin);

    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) { // Se for um número, empilha
            push(&l, expression[i] - '0'); // Converte char para int
        } 
        else if (expression[i] == '+' || expression[i] == '-' || 
                 expression[i] == '*' || expression[i] == '/') {
            int a = pop(&l);
            int b = pop(&l);
            int result;

            switch (expression[i]) {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/': result = b / a; break;
            }

            push(&l, result); // Empilha o resultado
        }
    }

    // O último elemento na pilha é o resultado final
    printf("Result: %d\n", pop(&l));

    return 0;
}
