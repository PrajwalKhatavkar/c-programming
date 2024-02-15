#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to perform depth-first search
void dfs(struct TreeNode* node, int maxSoFar, int* count) {
    if (node == NULL) {
        return;
    }
    if (node->val >= maxSoFar) {
        (*count)++;
        maxSoFar = node->val;
    }
    dfs(node->left, maxSoFar, count);
    dfs(node->right, maxSoFar, count);
}

// Function to count good nodes in the binary tree
int goodNodes(struct TreeNode* root) {
    int count = 0;
    dfs(root, root->val, &count);
    return count;
}

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // Example 1
    struct TreeNode* root1 = newNode(3);
    root1->left = newNode(1);
    root1->right = newNode(4);
    root1->left->left = newNode(3);
    root1->right->left = newNode(1);
    root1->right->right = newNode(5);

    printf("Output for Example 1: %d\n", goodNodes(root1));

    // Example 2
    struct TreeNode* root2 = newNode(3);
    root2->left = newNode(3);
    root2->right = newNode(4);
    root2->left->right = newNode(4);
    root2->right->left = newNode(2);

    printf("Output for Example 2: %d\n", goodNodes(root2));

    // Example 3
    struct TreeNode* root3 = newNode(1);

    printf("Output for Example 3: %d\n", goodNodes(root3));

    return 0;
}
