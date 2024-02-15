#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to count paths with given sum starting from a node
int countPaths(struct TreeNode* node, int targetSum) {
    if (node == NULL) {
        return 0;
    }
    // Check if the current node itself contributes to the targetSum
    int count = (node->val == targetSum) ? 1 : 0;
    // Recursively count paths starting from the left and right child nodes
    count += countPaths(node->left, targetSum - node->val);
    count += countPaths(node->right, targetSum - node->val);
    return count;
}

// Function to count paths with given sum in the binary tree
int pathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return 0;
    }
    // Count paths starting from the current node and recursively from its children
    int countFromRoot = countPaths(root, targetSum);
    int countFromLeft = pathSum(root->left, targetSum);
    int countFromRight = pathSum(root->right, targetSum);
    // Total count is the sum of counts from all paths
    return countFromRoot + countFromLeft + countFromRight;
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
    struct TreeNode* root1 = newNode(10);
    root1->left = newNode(5);
    root1->right = newNode(-3);
    root1->left->left = newNode(3);
    root1->left->right = newNode(2);
    root1->right->right = newNode(11);
    root1->left->left->left = newNode(3);
    root1->left->left->right = newNode(-2);
    root1->left->right->right = newNode(1);

    printf("Output for Example 1: %d\n", pathSum(root1, 8));

    // Example 2
    struct TreeNode* root2 = newNode(5);
    root2->left = newNode(4);
    root2->right = newNode(8);
    root2->left->left = newNode(11);
    root2->left->left->left = newNode(7);
    root2->left->left->right = newNode(2);
    root2->right->left = newNode(13);
    root2->right->right = newNode(4);
    root2->right->right->left = newNode(5);
    root2->right->right->right = newNode(1);

    printf("Output for Example 2: %d\n", pathSum(root2, 22));

    return 0;
}
