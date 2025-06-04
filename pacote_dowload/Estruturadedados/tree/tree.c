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

// Function prototype to print the entire tree (preorder traversal)
void print(Node*);

int main() {
    // Pointer to the root of the tree, initially NULL
    Node *tree = 0;

    // Manually constructing the binary tree:
    // Creating the root node with value 4
    tree = create(4, 0, 0);
    
    // Creating the children of the root node
    tree->left = create(2, 0, 0);  // Left child (2)
    tree->right = create(6, 0, 0); // Right child (6)

    // Creating the children of node 2
    tree->left->left = create(1, 0, 0);  // Left child of 2 (1)
    tree->left->right = create(3, 0, 0); // Right child of 2 (3)

    // Creating the children of node 6
    tree->right->left = create(5, 0, 0);  // Left child of 6 (5)
    tree->right->right = create(7, 0, 0); // Right child of 6 (7)

    // Print the tree using a preorder traversal
    print(tree);

    return 0; // End of the program
}

// Function to create a new tree node
Node *create(int value, Node *sleft, Node *sright) {
    // Dynamically allocate memory for a new node
    Node *new;
    new = (Node *)malloc(sizeof(Node));

    // Check if memory allocation was successful
    if (!new) {
        return 0; // Return NULL in case of failure
    }

    // Assign values to the new node
    new->data = value;
    new->left = sleft;
    new->right = sright;

    return new; // Return the pointer to the newly created node
}

// Function to print the tree using preorder traversal
void print(Node *root) {
    if (root) { // If the current node is not NULL
        printf("%d ", root->data); // Print the value of the node
        print(root->left);         // Recursively print the left subtree
        print(root->right);        // Recursively print the right subtree
    }
    else {
        return; // Base case: if the node is NULL, return
    }
}