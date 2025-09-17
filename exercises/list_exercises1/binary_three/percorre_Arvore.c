/*
2) Percursos em Árvore
Implemente funções recursivas que percorram a árvore em:
- Pré-ordem (Root, Left, Right)
- In-ordem (Left, Root, Right)
- Pós-ordem (Left, Right, Root)
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of the binary tree node structure
struct node {
    int data;            // Value stored in the node
    struct node *left;   // Pointer to the left child
    struct node *right;  // Pointer to the right child
};

// Define an alias "Node" for "struct node" to simplify usage
typedef struct node Node;

// Function prototype to create a new node
Node *create(int, Node*, Node*);

// Function prototypes
void mostra_infix(Node*);
void mostra_prefix(Node*);
void mostra_sufix(Node*);

int main() {
    Node *tree = 0;

    // Manually constructing the binary tree:
    tree = create(4, 0, 0);
    tree->left = create(2, 0, 0);
    tree->right = create(6, 0, 0);

    tree->left->left = create(1, 0, 0);
    tree->left->right = create(3, 0, 0);

    tree->right->left = create(5, 0, 0);
    tree->right->right = create(7, 0, 0);

    printf("Infix: ");
    mostra_infix(tree);
    printf("\n");

    printf("Prefix: ");
    mostra_prefix(tree);
    printf("\n");

    printf("Sufix: ");
    mostra_sufix(tree);
    printf("\n");

    return 0;
}

// Function to create a new tree node
Node *create(int value, Node *sleft, Node *sright) {
    Node *new;
    new = (Node *)malloc(sizeof(Node));

    if (!new) return 0;

    new->data = value;
    new->left = sleft;
    new->right = sright;

    return new;
}

// Preorder traversal
void mostra_prefix(Node *root) {
    if (root) {
        printf("%d ", root->data);
        mostra_prefix(root->left);
        mostra_prefix(root->right);
    }
}

// Inorder traversal
void mostra_infix(Node *root) {
    if (root) {
        mostra_infix(root->left);
        printf("%d ", root->data);
        mostra_infix(root->right);
    }
}

// Postorder traversal
void mostra_sufix(Node *root) {
    if (root) {
        mostra_sufix(root->left);
        mostra_sufix(root->right);
        printf("%d ", root->data);
    }
}
