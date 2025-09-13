/*
7) Verificar se é BST
Implemente uma função que, dada uma árvore binária qualquer,
determine se ela satisfaz as propriedades de uma árvore binária de busca.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "three.c" // Inclui a definição da estrutura Node
// Função para verificar se a árvore é uma BST

int ehBST(Node* root, int min, int max) {
    if (root == NULL) {
        return 1; // Árvore vazia é uma BST
    }
    if (root->data < min || root->data > max) {
        return 0; // Violação da propriedade BST
    }
    // Verifica recursivamente os subárvores esquerda e direita
    return ehBST(root->left, min, root->data - 1) &&
           ehBST(root->right, root->data + 1, max);
}

// Função auxiliar para iniciar a verificação
int verificaBST(Node* root) {
    return ehBST(root, INT_MIN, INT_MAX);
}