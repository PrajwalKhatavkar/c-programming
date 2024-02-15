#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue node structure for level-order traversal
struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};

// Queue structure
struct Queue {
    struct QueueNode *front, *rear;
};

// Function to create a new queue node
struct QueueNode* newQueueNode(struct TreeNode* node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue a node into the queue
void enqueue(struct Queue* queue, struct TreeNode* node) {
    struct QueueNode* newNode = newQueueNode(node);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue a node from the queue
struct TreeNode* dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    struct QueueNode* temp = queue->front;
    struct TreeNode* node = temp->node;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return node;
}

// Function to return the level with the maximum sum
int maxLevelSum(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    // Initialize variables to track the level with the maximum sum
    int maxLevel = 1;
    int maxSum = INT_MIN;

    // Initialize a queue for level-order traversal
    struct Queue* queue = createQueue();
    enqueue(queue, root);
    int level = 1;

    // Perform level-order traversal
    while (queue->front != NULL) {
        int levelSum = 0;
        int levelSize = queue->rear - queue->front + 1;

        // Traverse the current level
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(queue);
            levelSum += node->val;

            if (node->left) {
                enqueue(queue, node->left);
            }
            if (node->right) {
                enqueue(queue, node->right);
            }
        }

        // Update the level with the maximum sum if needed
        if (levelSum > maxSum) {
            maxSum = levelSum;
            maxLevel = level;
        }

        // Move to the next level
        level++;
    }

    // Return the level with the maximum sum
    return maxLevel;
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
    root1->left = newNode(7);
    root1->right = newNode(0);
    root1->left->left = newNode(7);
    root1->left->right = newNode(-8);
    int result1 = maxLevelSum(root1);
    printf("Example 1 output: %d\n", result1);

    // Example 2
    struct TreeNode* root2 = newNode(989);
    root2->right = newNode(10250);
    root2->right->left = newNode(98693);
    root2->right->right = newNode(-89388);
    root2->right->left->right = newNode(-32127);
    int result2 = maxLevelSum(root2);
    printf("Example 2 output: %d\n", result2);

    return 0;
}
