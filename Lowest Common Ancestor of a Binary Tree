#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to find the lowest common ancestor (LCA) of two nodes
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // Base case: if the root is null or equal to either p or q, return the root
    if (root == NULL || root == p || root == q) {
        return root;
    }
    
    // Recursively search for the nodes p and q in the left and right subtrees
    struct TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
    
    // If both leftLCA and rightLCA are not null, it means p and q are present in different subtrees, so return the root
    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }
    
    // If leftLCA is not null, return leftLCA; otherwise, return rightLCA
    return (leftLCA != NULL) ? leftLCA : rightLCA;
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
    root1->right->left = newNode(0);
    root1->right->right = newNode(8);
    root1->left->right->left = newNode(7);
    root1->left->right->right = newNode(4);

    struct TreeNode* p1 = root1->left;
    struct TreeNode* q1 = root1->right;
    struct TreeNode* lca1 = lowestCommonAncestor(root1, p1, q1);
    printf("LCA of nodes %d and %d: %d\n", p1->val, q1->val, lca1->val);

    // Example 2
    struct TreeNode* p2 = root1->left;
    struct TreeNode* q2 = root1->left->right->right;
    struct TreeNode* lca2 = lowestCommonAncestor(root1, p2, q2);
    printf("LCA of nodes %d and %d: %d\n", p2->val, q2->val, lca2->val);

    // Example 3
    struct TreeNode* root3 = newNode(1);
    root3->right = newNode(2);
    struct TreeNode* p3 = root3;
    struct TreeNode* q3 = root3->right;
    struct TreeNode* lca3 = lowestCommonAncestor(root3, p3, q3);
    printf("LCA of nodes %d and %d: %d\n", p3->val, q3->val, lca3->val);

    return 0;
}
