#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to find the longest ZigZag path recursively
void dfs(struct TreeNode* node, int leftLen, int rightLen, int* maxLen) {
    if (node == NULL) {
        return;
    }
    
    *maxLen = (*maxLen > leftLen) ? *maxLen : leftLen;
    *maxLen = (*maxLen > rightLen) ? *maxLen : rightLen;

    if (node->left != NULL) {
        dfs(node->left, rightLen + 1, 0, maxLen);
    }
    if (node->right != NULL) {
        dfs(node->right, 0, leftLen + 1, maxLen);
    }
}

// Function to calculate the longest ZigZag path in the binary tree
int longestZigZag(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int maxLen = 0;
    dfs(root->left, 1, 0, &maxLen);
    dfs(root->right, 0, 1, &maxLen);
    
    return maxLen;
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
    struct TreeNode* root1 = newNode(1);
    root1->right = newNode(1);
    root1->right->left = newNode(1);
    root1->right->right = newNode(1);
    root1->right->right->right = newNode(1);

    printf("Output for Example 1: %d\n", longestZigZag(root1));

    // Example 2
    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(1);
    root2->right = newNode(1);
    root2->left->right = newNode(1);
    root2->right->left = newNode(1);
    root2->right->right = newNode(1);
    root2->left->right->left = newNode(1);

    printf("Output for Example 2: %d\n", longestZigZag(root2));

    return 0;
}
