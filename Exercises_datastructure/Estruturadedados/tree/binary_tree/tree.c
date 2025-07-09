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

// Function prototypes
Node* create(int);
Node* rotate_right(Node*);
Node* rotate_left(Node*);
Node* insert(Node*, int);
Node* delete(Node*, int);
void show_preorder(Node*);
void show_inorder(Node*);
void show_postorder(Node*);
Node* clean(Node*);
int node_count(Node*);
int height(Node*);
int max(int, int);
int get_balance(Node*);

int main() {
    Node *tree = NULL; // Initialize an empty tree

    // Insert elements into the tree
    /*
    tree = insert(tree, 8);
    tree = insert(tree, 3);
    tree = insert(tree, 2);
    tree = insert(tree, 5);
    tree = insert(tree, 10);
    */

    tree = insert(tree, 15);
    tree = insert(tree, 22);
    tree = insert(tree, 12);
    tree = insert(tree, 14);
    tree = insert(tree, 17);
    tree = insert(tree, 10);
    tree = insert(tree, 24);
    tree = insert(tree, 19);
    tree = insert(tree, 21);
    tree = insert(tree, 11);
    tree = insert(tree, 18);
    tree = insert(tree, 16);

    printf("Tree in pre-order: ");
    show_preorder(tree); // Show the tree in pre-order traversal
    printf("\n");
    printf("Tree in sorted order: ");
    show_inorder(tree);
    printf("\n");
    printf("Tree in post-order: ");
    show_postorder(tree); // Show the tree in post-order traversal
    printf("\n");

    printf("Number of nodes: %d\n", node_count(tree)); // Count the number of nodes
    printf("Height of the tree: %d\n", height(tree)); // Calculate the height of the tree
    printf("Height of the left subtree: %d\n", height(tree->left)); // Height of the left subtree
    printf("Height of the right subtree: %d\n", height(tree->right)); // Height of the right subtree

    // Clean up the tree
    tree = clean(tree);
    return 0;
}
// Function to create a new tree node
Node *create(int value) {
    // Dynamically allocate memory for a new node
    Node *new = (Node *)malloc(sizeof(Node));
    // Check if memory allocation was successful
    if (!new) {
        return NULL; // Return NULL in case of failure
    }

    // Assign values to the new node
    new->data = value;
    new->left = NULL;
    new->right = NULL;

    return new; // Return the newly created node
}

//function to rotate the tree to the right
Node *rotate_right(Node *root) {
    Node *new_root = root->left; // Set new root to the left child of the current root
    root->left = new_root->right; // Move the right child of the new root to the left of the current root
    new_root->right = root; // Set the current root as the right child of the new root
    return new_root; // Return the new root
}

//function to rotate the tree to the left
Node *rotate_left(Node *root) {
    Node *new_root = root->right; // Set new root to the right child of the current root
    root->right = new_root->left; // Move the left child of the new root to the right of the current root
    new_root->left = root; // Set the current root as the left child of the new root
    return new_root; // Return the new root
}

// Function to insert a value into the binary tree
Node *insert(Node *root, int value) {
    // If the tree is empty, create a new node and return it
    if (root == NULL) {
        return create(value);
    }

    // Recursively insert the value into the left or right subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    else {
        return root; // Duplicate values are not allowed, return the unchanged tree pointer
    }

    // check the balance factor of the current node
    int balance = get_balance(root); // Get the balance factor of the current node

    // Cases of imbalance
    
    // Left Left Case (LL)
    if (balance > 1 && value < root->left->data) {
        return rotate_right(root); // Perform right rotation
    }

    // Right Right Case (RR)
    if (balance < -1 && value > root->right->data) {
        return rotate_left(root); // Perform left rotation
    }

    // Left Right Case (LR)
    if (balance > 1 && value > root->left->data) {
        root->left = rotate_left(root->left); // Perform left rotation on the left child
        return rotate_right(root); // Perform right rotation
    }

    // Right Left Case (RL)
    if (balance < -1 && value < root->right->data) {
        root->right = rotate_right(root->right); // Perform right rotation on the right child
        return rotate_left(root); // Perform left rotation
    }

    return root; // Return the unchanged tree pointer
}

// Function to delete a node from the binary tree (BST)
Node *delete(Node *root, int value) {
    // If the tree is empty, return NULL
    if (!root) {
        return NULL;
    }

    // Step 1: Search for the value to be removed
    if (value < root->data) {
        root->left = delete(root->left, value); // Search in the left subtree
    } else if (value > root->data) {
        root->right = delete(root->right, value); // Search in the right subtree
    } else {
        // Node with 0 or 1 child
        if (!root->left || !root->right) {
            Node *temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }

        // Node with 2 children: find the in-order successor
        Node *temp = root->right;
        while (temp && temp->left)
            temp = temp->left;

        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    // Step 2: Rebalance AVL
    int balance = get_balance(root); // Get the balance factor of the current node

    // Cases of imbalance:

    // Left Left Case (LL)
    if (balance > 1 && get_balance(root->left) >= 0) {
        return rotate_right(root); // Perform right rotation
    }

    // Left Right Case (LR)
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = rotate_left(root->left); // Perform left rotation on the left child
        return rotate_right(root); // Perform right rotation
    }

    // Right Right Case (RR)
    if (balance < -1 && get_balance(root->right) <= 0) {
        return rotate_left(root); // Perform left rotation
    }
    
    // Right Left Case (RL)
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = rotate_right(root->right); // Perform right rotation on the right child
        return rotate_left(root); // Perform left rotation
    }

    return root; // Return the unchanged tree pointer
}

// Function to show the tree in pre-order traversal
void show_preorder(Node *root) {
    if (root) {
        printf("%d ", root->data); // Visit the root
        show_preorder(root->left); // Traverse the left subtree
        show_preorder(root->right); // Traverse the right subtree
    }
    else return; // Base case: if the node is NULL, do nothing
}

// Function to show the tree in sorted order (in-order traversal)
void show_inorder(Node *root) {
    if (root) {
        show_inorder(root->left);
        printf("%d ", root->data);
        show_inorder(root->right);
    }
    else return; // Base case: if the node is NULL, do nothing
}

// Function to show the tree in post-order traversal
void show_postorder(Node *root) {
    if (root) {
        show_postorder(root->left); // Traverse the left subtree
        show_postorder(root->right); // Traverse the right subtree
        printf("%d ", root->data); // Visit the root
    }
    else return; // Base case: if the node is NULL, do nothing
}

// Function to free all nodes in the tree
Node *clean(Node *root) {
    if (root) { // If the current node is not NULL
        root->left = clean(root->left);   // Recursively clean the left subtree
        root->right =  clean(root->right);  // Recursively clean the right subtree
        free(root);          // Free the current node
    }
    return NULL; // Return NULL after cleaning up the tree
}

// Function to count the number of nodes in the tree
int node_count(Node *root) {
    int a, b;
    if (!root) {
        return 0; // Base case: if the node is NULL, return 0
    }
    a = node_count(root->left); // Count nodes in the left subtree
    b = node_count(root->right); // Count nodes in the right subtree
    return (a + b + 1); // Return total count (left + right + 1 for the current node)
}

// Function to calculate the height of the tree
int height(Node *root) {
    int a, b;
    if (!root) {
        return 0; // Base case: if the node is NULL, return 0
    }
    a = height(root->left); // Height of the left subtree
    b = height(root->right); // Height of the right subtree
    return (a > b ? a : b) + 1; // Return the maximum height + 1 for the current node
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b; // Return the maximum of a and b
}

// Function to get the balance factor of a node
int get_balance(Node *node) {
    if (!node) {
        return 0; // Base case: if the node is NULL, return 0
    }
    return height(node->left) - height(node->right); // Return the balance factor (left height - right height)
}