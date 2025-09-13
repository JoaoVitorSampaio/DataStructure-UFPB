/*
1) Construção de Árvore Binária
Implemente uma estrutura de dados para representar uma árvore binária.
Crie uma função para inserir novos nós na árvore.
*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um novo nó na árvore binária
Node* insert(Node **root, int data) {
    if (*root == NULL) {
        Node* newNode = createNode(data);
        if(!newNode){
            return 0;
        }
        *root = newNode;
      }
    else {
        if((*root)->data > data){
            insert(&((*root)->left), data);
        } 
        else {
            insert(&((*root)->right), data);
        }
    }
    return 1;
}