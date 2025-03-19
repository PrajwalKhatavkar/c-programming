#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to check if two trees are leaf-similar
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    // Helper function to traverse the tree and collect leaf values
    void collectLeafValues(struct TreeNode* root, int* leafValues, int* size) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            leafValues[(*size)++] = root->val;
        }
        collectLeafValues(root->left, leafValues, size);
        collectLeafValues(root->right, leafValues, size);
    }
    
    // Collect leaf values for both trees
    int leafValues1[200] = {0}; // Assuming max 200 leaf nodes
    int leafValues2[200] = {0};
    int size1 = 0, size2 = 0;
    collectLeafValues(root1, leafValues1, &size1);
    collectLeafValues(root2, leafValues2, &size2);
    
    // If sizes of leaf value sequences are different, return false
    if (size1 != size2) {
        return false;
    }
    
    // Compare leaf value sequences
    for (int i = 0; i < size1; i++) {
        if (leafValues1[i] != leafValues2[i]) {
            return false;
        }
    }
    
    return true;
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
    root1->left = newNode(5);
    root1->right = newNode(1);
    root1->left->left = newNode(6);
    root1->left->right = newNode(2);
    root1->left->right->left = newNode(7);
    root1->left->right->right = newNode(4);
    root1->right->left = newNode(9);
    root1->right->right = newNode(8);

    struct TreeNode* root2 = newNode(3);
    root2->left = newNode(5);
    root2->right = newNode(1);
    root2->left->left = newNode(6);
    root2->left->right = newNode(7);
    root2->left->right->left = newNode(4);
    root2->left->right->right = newNode(2);
    root2->right->right = newNode(8);
    root2->right->right->left = newNode(9);

    printf("Output for Example 1: %s\n", leafSimilar(root1, root2) ? "true" : "false");

    // Example 2
    struct TreeNode* root3 = newNode(1);
    root3->left = newNode(2);
    root3->right = newNode(3);

    struct TreeNode* root4 = newNode(1);
    root4->left = newNode(3);
    root4->right = newNode(2);

    printf("Output for Example 2: %s\n", leafSimilar(root3, root4) ? "true" : "false");

    return 0;
}
