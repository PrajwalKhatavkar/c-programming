#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to search for a node with the given value in a BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }

    // If the value is less than the current node's value, search in the left subtree
    if (val < root->val) {
        return searchBST(root->left, val);
    }
    // If the value is greater than the current node's value, search in the right subtree
    else {
        return searchBST(root->right, val);
    }
}

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into a BST
struct TreeNode* insertBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return newNode(val);
    }

    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }

    return root;
}

// Function to print the inorder traversal of a BST
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

int main() {
    // Example 1
    struct TreeNode* root1 = newNode(4);
    root1->left = newNode(2);
    root1->right = newNode(7);
    root1->left->left = newNode(1);
    root1->left->right = newNode(3);
    int val1 = 2;
    struct TreeNode* result1 = searchBST(root1, val1);
    printf("Example 1 output: ");
    inorderTraversal(result1);
    printf("\n");

    // Example 2
    struct TreeNode* root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(7);
    root2->left->left = newNode(1);
    root2->left->right = newNode(3);
    int val2 = 5;
    struct TreeNode* result2 = searchBST(root2, val2);
    printf("Example 2 output: ");
    inorderTraversal(result2);
    printf("\n");

    return 0;
}
