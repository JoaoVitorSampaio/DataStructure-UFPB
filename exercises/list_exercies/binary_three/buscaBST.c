/*
5) Busca em Árvore Binária de Busca (BST)
Dada uma árvore binária de busca, implemente uma função que receba
um valor e retorne se ele está ou não presente na árvore.
*/
#include <stdio.h>
#include <stdlib.h>
#include "three.c" // Inclui a definição da estrutura Node

int buscarBST(Node* root, int value) {
    Node* current = root;
    
    while (current != NULL) {
        if (current->data == value) {
            return 1; // Valor encontrado
        } else if (value < current->data) {
            current = current->left; // Ir para a subárvore esquerda
        } else {
            current = current->right; // Ir para a subárvore direita
        }
    }