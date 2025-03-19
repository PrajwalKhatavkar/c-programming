#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return head;
    }
    
    struct ListNode *oddHead = head;
    struct ListNode *evenHead = head->next;
    struct ListNode *oddTail = oddHead;
    struct ListNode *evenTail = evenHead;
    struct ListNode *curr = evenHead->next;
    int index = 3; // Start from the third node (index = 2)

    // Traverse the list and divide it into odd and even lists
    while (curr != NULL) {
        if (index % 2 == 1) { // Odd index
            oddTail->next = curr;
            oddTail = oddTail->next;
        } else { // Even index
            evenTail->next = curr;
            evenTail = evenTail->next;
        }
        curr = curr->next;
        index++;
    }
    
    oddTail->next = evenHead; // Connect the tail of odd list to the head of even list
    evenTail->next = NULL; // Mark the end of the even list
    
    return oddHead;
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

    head1 = oddEvenList(head1);
    printf("Reordered list: ");
    printList(head1);

    // Example 2
    struct ListNode* head2 = newNode(2);
    head2->next = newNode(1);
    head2->next->next = newNode(3);
    head2->next->next->next = newNode(5);
    head2->next->next->next->next = newNode(6);
    head2->next->next->next->next->next = newNode(4);
    head2->next->next->next->next->next->next = newNode(7);

    printf("Original list: ");
    printList(head2);

    head2 = oddEvenList(head2);
    printf("Reordered list: ");
    printList(head2);

    return 0;
}
