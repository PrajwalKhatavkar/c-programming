#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddleNode(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return NULL; // No middle node to delete
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;
    
    // Move slow pointer one step at a time and fast pointer two steps at a time
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Delete the middle node by adjusting pointers
    prev->next = slow->next;
    free(slow);
    
    return head;
}

// Function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    // Example 1
    struct ListNode* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(4);
    head1->next->next->next = newNode(7);
    head1->next->next->next->next = newNode(1);
    head1->next->next->next->next->next = newNode(2);
    head1->next->next->next->next->next->next = newNode(6);

    printf("Original list: ");
    printList(head1);

    head1 = deleteMiddleNode(head1);
    printf("Modified list: ");
    printList(head1);

    // Example 2
    struct ListNode* head2 = newNode(1);
    head2->next = newNode(2);
    head2->next->next = newNode(3);
    head2->next->next->next = newNode(4);

    printf("Original list: ");
    printList(head2);

    head2 = deleteMiddleNode(head2);
    printf("Modified list: ");
    printList(head2);

    // Example 3
    struct ListNode* head3 = newNode(2);
    head3->next = newNode(1);

    printf("Original list: ");
    printList(head3);

    head3 = deleteMiddleNode(head3);
    printf("Modified list: ");
    printList(head3);

    return 0;
}
