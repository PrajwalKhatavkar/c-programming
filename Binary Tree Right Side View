#include <stdio.h>
#include <stdlib.h>

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

// Function to return the right side view of a binary tree
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Initialize an array to store the right side view
    int* result = (int*)malloc(100 * sizeof(int));
    int index = 0;

    // Initialize a queue for level-order traversal
    struct Queue* queue = createQueue();
    enqueue(queue, root);

    // Perform level-order traversal
    while (queue->front != NULL) {
        int levelSize = queue->rear - queue->front + 1;
        struct TreeNode* rightmostNode = NULL;

        // Traverse the current level
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(queue);
            if (i == levelSize - 1) {
                rightmostNode = node;
            }
            if (node->left) {
                enqueue(queue, node->left);
            }
            if (node->right) {
                enqueue(queue, node->right);
            }
        }

        // Store the value of the rightmost node in the current level
        result[index++] = rightmostNode->val;
    }

    // Set the return size and return the result array
    *returnSize = index;
    return result;
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
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->right = newNode(5);
    root1->right->right = newNode(4);
    int size1;
    int* result1 = rightSideView(root1, &size1);
    printf("Example 1 output: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");

    // Example 2
    struct TreeNode* root2 = newNode(1);
    root2->right = newNode(3);
    int size2;
    int* result2 = rightSideView(root2, &size2);
    printf("Example 2 output: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");

    // Example 3
    struct TreeNode* root3 = NULL;
    int size3;
    int* result3 = rightSideView(root3, &size3);
    printf("Example 3 output: ");
    for (int i = 0; i < size3; i++) {
        printf("%d ", result3[i]);
    }
    printf("\n");

    return 0;
}
