//
// Created by PREM on 10-11-2025.
//

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int key) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit program if memory is full
    }

    // Assign data and initialize children pointers to NULL
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to insert a new key into the BST (recursively)
struct Node* insert(struct Node* root, int key) {
    // 1. Base Case: If the tree (or subtree) is empty,
    //    create a new root node and return it as the new root.
    if (root == NULL) {
        return createNode(key);
    }

    // 2. Recursive Step: Otherwise, traverse down the tree
    if (key < root->key) {
        // If the key is smaller, it belongs in the left subtree
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        // If the key is larger, it belongs in the right subtree
        root->right = insert(root->right, key);
    }
    // Note: If key == root->key, we do nothing (no duplicates allowed)

    // 3. Return the (possibly updated) root pointer
    return root;
}

// --- TRAVERSAL FUNCTIONS ---

/**
 * Inorder Traversal (Left, Root, Right)
 * This traversal visits nodes in ascending (sorted) order.
 */
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  // 1. Go to the left child
        printf("%d ", root->key);      // 2. Visit the root node
        inorderTraversal(root->right); // 3. Go to the right child
    }
}

/**
 * Preorder Traversal (Root, Left, Right)
 * This traversal is useful for copying a tree.
 */
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);       // 1. Visit the root node
        preorderTraversal(root->left);  // 2. Go to the left child
        preorderTraversal(root->right); // 3. Go to the right child
    }
}

/**
 * Postorder Traversal (Left, Right, Root)
 * This traversal is useful for deleting a tree (frees children before parent).
 */
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);  // 1. Go to the left child
        postorderTraversal(root->right); // 2. Go to the right child
        printf("%d ", root->key);      // 3. Visit the root node
    }
}

// Function to free the memory allocated for the tree (good practice)
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to test the implementation
int main() {
    struct Node* root = NULL;

    // Build the tree by inserting nodes
    // The first node inserted becomes the root
    root = insert(root, 50);

    // Insert remaining nodes
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    /* The resulting tree will look like this:
     *
     *   50
     * /    \
     * 30     70
     * /  \   /  \
     * 20  40 60  80
     */

    printf("Inorder traversal (Left, Root, Right):\n");
    inorderTraversal(root);
    printf("\n\n");

    printf("Preorder traversal (Root, Left, Right):\n");
    preorderTraversal(root);
    printf("\n\n");

    printf("Postorder traversal (Left, Right, Root):\n");
    postorderTraversal(root);
    printf("\n\n");

    // Clean up memory
    freeTree(root);
    root = NULL;

    return 0;
}