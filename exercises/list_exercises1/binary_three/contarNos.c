/*
4) Contagem de Nós e Folhas
a) Escreva uma função que conte o número total de nós da árvore.
b) Escreva outra função que conte quantos nós folha (sem filhos) existem
*/

#include <stdio.h>
#include <stdlib.h>
#include "three.c" // Inclui a definição da estrutura Node

int contarNos(Node* root) {
    if (root == NULL) {
        return 0; // Árvore vazia tem 0 nós
    } else {
        return 1 + contarNos(root->left) + contarNos(root->right);
    }
}

int contarNosFolha(Node* root) {
    if (root == NULL) {
        return 0; // Árvore vazia tem 0 nós folha
    }
    if (root->left == NULL && root->right == NULL) {
        return 1; // Nó folha encontrado
    } else {
        return contarNosFolha(root->left) + contarNosFolha(root->right);
    }
}