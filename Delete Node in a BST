#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to find the inorder successor of a node
struct TreeNode* inorderSuccessor(struct TreeNode* root) {
    struct TreeNode* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with the given key from a BST
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    // If the key is smaller than the root's value, search in the left subtree
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    // If the key is greater than the root's value, search in the right subtree
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    // If key is the same as root's key, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = inorderSuccessor(root->right);

        // Copy the inorder successor's content to this node
        root->val = temp->val;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform inorder traversal of a BST
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

int main() {
    // Example 1
    struct TreeNode* root1 = newNode(5);
    root1->left = newNode(3);
    root1->right = newNode(6);
    root1->left->left = newNode(2);
    root1->left->right = newNode(4);
    root1->right->right = newNode(7);
    int key1 = 3;
    printf("Example 1 output: ");
    inorderTraversal(deleteNode(root1, key1));
    printf("\n");

    // Example 2
    struct TreeNode* root2 = newNode(5);
    root2->left = newNode(3);
    root2->right = newNode(6);
    root2->left->left = newNode(2);
    root2->left->right = newNode(4);
    root2->right->right = newNode(7);
    int key2 = 0;
    printf("Example 2 output: ");
    inorderTraversal(deleteNode(root2, key2));
    printf("\n");

    // Example 3
    struct TreeNode* root3 = NULL;
    int key3 = 0;
    printf("Example 3 output: ");
    inorderTraversal(deleteNode(root3, key3));
    printf("\n");

    return 0;
}
