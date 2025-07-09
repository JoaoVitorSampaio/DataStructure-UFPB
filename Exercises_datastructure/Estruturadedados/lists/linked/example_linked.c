#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista encadeada
typedef struct knot {
    int data;           // Valor armazenado no nó
    struct knot *next;  // Ponteiro para o próximo nó
} Knot;

// Funções para manipulação da lista
void create(Knot **l);
void insert(Knot **l);
void delete(Knot **l);
void clean(Knot **l);
void print(Knot *l);
int menu();

int main() {
    Knot *l;  // Ponteiro para o início da lista
    int opt;  // Variável para armazenar a opção do usuário

    create(&l); // Inicializa a lista vazia

    do {
        opt = menu(); // Exibe o menu e recebe a opção do usuário

        switch (opt) {
            case 1:
                insert(&l); // Insere um novo elemento na lista
                break;
            case 2:
                delete(&l); // Remove um elemento da lista
                break;
            case 3:
                clean(&l); // Remove todos os elementos da lista
                break;
            case 4:
                print(l); // Exibe os elementos da lista
                break;
            case 5:
                break; // Sai do programa
            default:
                printf("Opcao invalida!\n");
        }
    } while (opt != 5); // Continua até o usuário escolher sair

    return 0;
}

// Inicializa a lista definindo a cabeça como NULL
void create(Knot **l) {
    *l = NULL;
}

// Função para inserir um elemento no início da lista
void insert(Knot **l) {
    Knot *new = (Knot *)malloc(sizeof(Knot)); // Aloca memória para o novo nó
    if (new == NULL) { // Verifica se a memória foi alocada corretamente
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    printf("Digite o valor a ser inserido: ");
    scanf("%d", &new->data); // Lê o valor do usuário

    new->next = *l; // O novo nó aponta para o antigo primeiro nó
    *l = new; // Atualiza a cabeça da lista para o novo nó
}

// Função para remover um elemento da lista
void delete(Knot **l) {
    if (*l == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    int n;
    printf("Digite o valor a ser removido: ");
    scanf("%d", &n); // Lê o valor a ser removido

    Knot *aux = *l, *prev = NULL;

    // Percorre a lista procurando o valor
    while (aux != NULL && aux->data != n) {
        prev = aux;
        aux = aux->next;
    }

    if (aux == NULL) { // Se o valor não for encontrado
        printf("Elemento nao encontrado!\n");
        return;
    }

    if (prev == NULL) { // Se o elemento está no início da lista
        *l = aux->next;
    } else { // Se o elemento está no meio ou no final
        prev->next = aux->next;
    }

    free(aux); // Libera a memória do nó removido
    printf("Elemento removido com sucesso!\n");
}

// Função para limpar toda a lista
void clean(Knot **l) {
    Knot *aux;
    while (*l != NULL) {
        aux = *l;
        *l = (*l)->next;
        free(aux);
    }
    printf("Lista limpa!\n");
}

// Função para imprimir todos os elementos da lista
void print(Knot *l) {
    if (l == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    printf("Lista: ");
    while (l != NULL) {
        printf("%d -> ", l->data);
        l = l->next;
    }
    printf("NULL\n");
}

// Função para exibir o menu e capturar a opção do usuário
int menu() {
    int opt;
    printf("\nMENU:\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Remover elemento\n");
    printf("3 - Limpar lista\n");
    printf("4 - Imprimir lista\n");
    printf("5 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opt);
    return opt;
}