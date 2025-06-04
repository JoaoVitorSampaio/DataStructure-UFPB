#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

struct stack {
    double data[MAX]; 
    int ctr;
};

// Funções da pilha
void create(struct stack *l);
int is_empty(struct stack *l);
int is_full(struct stack *l);
void push(struct stack *l, double data);
double pop(struct stack *l);
int is_double(const char *str);

void create(struct stack *l) {
    l->ctr = 0;
}

int is_empty(struct stack *l) {
    return l->ctr == 0;
}

int is_full(struct stack *l) {
    return l->ctr == MAX;
}

void push(struct stack *l, double data) {
    if (is_full(l)) {
        fprintf(stderr, "Erro: A pilha está cheia.\n");
        return;
    }
    l->data[l->ctr++] = data;
}

double pop(struct stack *l) { 
    if (is_empty(l)) {
        fprintf(stderr, "Erro: A pilha está vazia.\n");
        exit(1);
    }
    return l->data[--l->ctr];
}

int is_double(const char *str) {
    char *endptr;
    strtod(str, &endptr);
    return (*str != '\0' && *endptr == '\0');
}

// Função principal que avalia a expressão pós-fixa
int main() {
    struct stack l;
    create(&l);

    char expression[MAX];
    printf("Digite a expressão pós-fixa (separada por espaço): ");
    fgets(expression, MAX, stdin);

    char *token = strtok(expression, " \n");
    while (token != NULL) {
        if (is_double(token)) { 
            push(&l, strtod(token, NULL));
        } 
        else if (strlen(token) == 1 && strchr("+-*/%^#", token[0])) {
            if (is_empty(&l)) {
                fprintf(stderr, "Erro: Operandos insuficientes.\n");
                exit(1);
            }
            
            double a = pop(&l);
            double b = 0, result = 0;

            // Operação unária (somente 'a' é usado)
            if (token[0] != '#') {
                if (is_empty(&l)) {
                    fprintf(stderr, "Erro: Operandos insuficientes.\n");
                    exit(1);
                }
                b = pop(&l);
            }

            switch (token[0]) {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/': 
                    if (a == 0) {
                        fprintf(stderr, "Erro: Divisão por zero.\n");
                        exit(1);
                    }
                    result = b / a;
                    break;
                case '%': 
                    if (a == 0) {
                        fprintf(stderr, "Erro: Módulo por zero.\n");
                        exit(1);
                    }
                    result = fmod(b, a);
                    break;
                case '^': 
                    if (b < 0 && floor(a) != a) {
                        fprintf(stderr, "Erro: Expoente fracionário de número negativo.\n");
                        exit(1);
                    }
                    result = pow(b, a); 
                    break;
                case '#': result = a * a; break; // Elevar ao quadrado
                default:
                    fprintf(stderr, "Erro: Operador desconhecido %c\n", token[0]);
                    exit(1);
            }
            push(&l, result);
        } 
        else {
            fprintf(stderr, "Erro: Token inválido '%s'\n", token);
            exit(1);
        }

        token = strtok(NULL, " \n");
    }

    if (l.ctr == 1) { 
        printf("Resultado: %lf\n", pop(&l));
    } 
    else {
        fprintf(stderr, "Erro: Expressão inválida.\n");
        exit(1);
    }

    return 0;
}
