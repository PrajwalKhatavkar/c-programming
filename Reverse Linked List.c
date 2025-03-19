#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Iterative approach
struct ListNode* reverseListIterative(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    
    return prev;
}

// Recursive approach
struct ListNode* reverseListRecursive(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode* reversed = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return reversed;
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
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);

    printf("Original list: ");
    printList(head1);

    struct ListNode* reversed1 = reverseListIterative(head1);
    printf("Reversed list (iterative): ");
    printList(reversed1);

    // Example 2
    struct ListNode* head2 = newNode(1);
    head2->next = newNode(2);

    printf("Original list: ");
    printList(head2);

    struct ListNode* reversed2 = reverseListRecursive(head2);
    printf("Reversed list (recursive): ");
    printList(reversed2);

    // Example 3
    struct ListNode* head3 = NULL;

    printf("Original list: ");
    printList(head3);

    struct ListNode* reversed3 = reverseListIterative(head3);
    printf("Reversed list (iterative): ");
    printList(reversed3);

    return 0;
}
