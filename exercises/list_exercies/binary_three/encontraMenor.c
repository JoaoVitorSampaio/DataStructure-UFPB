/*
6) Menor e Maior Elemento em BST
Escreva funções para encontrar o menor e o maior valor de uma
árvore binária de busca.
*/

#include <stdio.h>
#include <stdlib.h>
#include "three.c" // Inclui a definição da estrutura Node

Node *encontraMenor(Node* root) {
    if (root == NULL) {
        return NULL; // Árvore vazia
    }
    Node* current = root;
    while (current->left != NULL) {
        current = current->left; // Ir para o filho esquerdo
    }
    return current; // Retorna o nó com o menor valor
}

Node *encontraMaior(Node* root) {
    if (root == NULL) {
        return NULL; // Árvore vazia
    }
    Node* current = root;
    while (current->right != NULL) {
        current = current->right; // Ir para o filho direito
    }
    return current; // Retorna o nó com o maior valor
}