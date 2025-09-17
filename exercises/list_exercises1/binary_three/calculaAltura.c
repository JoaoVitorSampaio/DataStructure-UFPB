/*
3) Altura da Árvore
Crie uma função recursiva que calcule a altura de uma árvore binária
(quantidade máxima de níveis da raiz até uma folha).
*/
#include <stdio.h>
#include <stdlib.h>
#include "three.c" // Inclui a definição da estrutura Node

int calculaAltura(Node* root) {
    if (root == NULL) {
        return -1; // Altura de árvore vazia é -1
    } else {
        int alturaEsquerda = calculaAltura(root->left);
        int alturaDireita = calculaAltura(root->right);
        if(alturaEsquerda > alturaDireita) {
            return alturaEsquerda + 1;
        } else {
            return alturaDireita + 1;
        }
    }
}