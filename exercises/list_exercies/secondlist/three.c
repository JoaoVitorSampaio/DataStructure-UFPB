#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore AVL
typedef struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
    int altura;
} Node;

// Protótipos das funções
Node* criarNo(int valor);
void liberar_arvore(Node* raiz);
int altura(Node* no);
int max(int a, int b);
void atualizar_altura(Node* no);
int fator_balanceamento(Node* no);
Node* rotacao_direita(Node* y);
Node* rotacao_esquerda(Node* x);
Node* inserir(Node* raiz, int valor);
Node* no_com_valor_minimo(Node* no);
Node* remover(Node* raiz, int valor);
void em_ordem(Node* raiz);

// --- Funções Auxiliares ---

// Cria um novo nó, com tratamento de erro de alocação
Node* criarNo(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para o nó.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->altura = 1; // Nó novo sempre tem altura 1
    return novo;
}

// Libera toda a memória alocada para a árvore (pós-ordem)
void liberar_arvore(Node* raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}

// Retorna a altura de um nó (0 se for NULL)
int altura(Node* no) {
    if (no == NULL) return 0;
    return no->altura;
}

// Retorna o maior de dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Atualiza a altura de um nó com base na altura de seus filhos
void atualizar_altura(Node* no) {
    if (no != NULL) {
        no->altura = 1 + max(altura(no->esquerda), altura(no->direita));
    }
}

// Calcula o fator de balanceamento de um nó
int fator_balanceamento(Node* no) {
    if (no == NULL) return 0;
    return altura(no->esquerda) - altura(no->direita);
}

// --- Rotações ---

// Rotação simples à direita
Node* rotacao_direita(Node* y) {
    Node* x = y->esquerda;
    Node* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    // Atualiza alturas na ordem correta (primeiro o filho, depois a nova raiz)
    atualizar_altura(y);
    atualizar_altura(x);

    return x; // Nova raiz da sub-árvore
}

// Rotação simples à esquerda
Node* rotacao_esquerda(Node* x) {
    Node* y = x->direita;
    Node* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    // Atualiza alturas
    atualizar_altura(x);
    atualizar_altura(y);

    return y; // Nova raiz da sub-árvore
}

// --- Funções Principais da AVL ---

// Balanceia o nó e retorna a nova raiz da sub-árvore
Node* balancear_no(Node* no, int valor) {
    atualizar_altura(no);
    int fb = fator_balanceamento(no);

    // Caso Esquerda-Esquerda
    if (fb > 1 && fator_balanceamento(no->esquerda) >= 0) {
        return rotacao_direita(no);
    }
    // Caso Esquerda-Direita
    if (fb > 1 && fator_balanceamento(no->esquerda) < 0) {
        no->esquerda = rotacao_esquerda(no->esquerda);
        return rotacao_direita(no);
    }
    // Caso Direita-Direita
    if (fb < -1 && fator_balanceamento(no->direita) <= 0) {
        return rotacao_esquerda(no);
    }
    // Caso Direita-Esquerda
    if (fb < -1 && fator_balanceamento(no->direita) > 0) {
        no->direita = rotacao_direita(no->direita);
        return rotacao_esquerda(no);
    }

    return no; // Nó já está balanceado
}

// Insere um valor na árvore AVL
Node* inserir(Node* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);
    else
        return raiz; // Não permite valores duplicados

    // Após a inserção, balanceia o nó ancestral
    return balancear_no(raiz, valor);
}

// Encontra o nó com o menor valor na sub-árvore (o mais à esquerda)
Node* no_com_valor_minimo(Node* no) {
    Node* atual = no;
    while (atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}

// Remove um valor da árvore AVL
Node* remover(Node* raiz, int valor) {
    if (raiz == NULL) return raiz;

    // Passo 1: Remoção padrão de BST
    if (valor < raiz->valor)
        raiz->esquerda = remover(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover(raiz->direita, valor);
    else {
        // Nó com um ou nenhum filho
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            Node* temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
            if (temp == NULL) { // Nenhum filho
                temp = raiz;
                raiz = NULL;
            } else { // Um filho
                *raiz = *temp; // Copia o conteúdo do filho
            }
            free(temp);
        } else {
            // Nó com dois filhos
            Node* temp = no_com_valor_minimo(raiz->direita);
            raiz->valor = temp->valor;
            raiz->direita = remover(raiz->direita, temp->valor);
        }
    }

    if (raiz == NULL) return raiz;

    // Passo 2: Balancear o nó ancestral
    return balancear_no(raiz, valor);
}

// --- Funções de Exibição e Teste ---

// Percurso em ordem para imprimir os valores
void em_ordem(Node* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        em_ordem(raiz->direita);
    }
}

int main() {
    Node* raiz = NULL;

    // Inserindo valores
    int valores_inserir[] = {10, 20, 30, 40, 50, 25};
    int n_inserir = sizeof(valores_inserir) / sizeof(valores_inserir[0]);
    printf("Inserindo valores: ");
    for (int i = 0; i < n_inserir; i++) {
        printf("%d ", valores_inserir[i]);
        raiz = inserir(raiz, valores_inserir[i]);
    }
    printf("\n");

    printf("Percurso em ordem da árvore AVL criada: ");
    em_ordem(raiz);
    printf("\n\n");

    // Removendo valores
    int valores_remover[] = {10, 40};
    int n_remover = sizeof(valores_remover) / sizeof(valores_remover[0]);
     for (int i = 0; i < n_remover; i++) {
        printf("Removendo o valor %d...\n", valores_remover[i]);
        raiz = remover(raiz, valores_remover[i]);
        printf("Percurso em ordem após remoção: ");
        em_ordem(raiz);
        printf("\n");
    }
   
    printf("\n");
    
    // Liberar memória antes de sair
    liberar_arvore(raiz);
    printf("Memória da árvore liberada com sucesso.\n");

    return 0;
}