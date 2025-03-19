#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int maxTwinSum(struct ListNode* head) {
    int maxSum = 0;
    struct ListNode* curr = head;
    int count = 0;
    
    // Traverse the linked list
    while (curr != NULL) {
        // Compute the index of the twin node
        int twinIndex = count % 2 == 0 ? count + 1 : count - 1;
        
        // Traverse to the twin node
        struct ListNode* twin = head;
        for (int i = 0; i < twinIndex; i++) {
            twin = twin->next;
        }
        
        // Compute the twin sum and update maxSum if needed
        int twinSum = curr->val + twin->val;
        maxSum = twinSum > maxSum ? twinSum : maxSum;
        
        // Move to the next node
        curr = curr->next;
        count++;
    }
    
    return maxSum;
}

// Function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    // Example 1
    struct ListNode* head1 = newNode(5);
    head1->next = newNode(4);
    head1->next->next = newNode(2);
    head1->next->next->next = newNode(1);

    printf("Maximum twin sum: %d\n", maxTwinSum(head1));

    // Example 2
    struct ListNode* head2 = newNode(4);
    head2->next = newNode(2);
    head2->next->next = newNode(2);
    head2->next->next->next = newNode(3);

    printf("Maximum twin sum: %d\n", maxTwinSum(head2));

    // Example 3
    struct ListNode* head3 = newNode(1);
    head3->next = newNode(100000);

    printf("Maximum twin sum: %d\n", maxTwinSum(head3));

    return 0;
}
