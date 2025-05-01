#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to reverse a portion of the linked list
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (left == right)
        return head;

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* leftTail = &dummy;
    struct ListNode* leftNode = head;

    // Move to the left position
    for (int i = 1; i < left; i++) {
        leftTail = leftTail->next;
        leftNode = leftNode->next;
    }

    struct ListNode* current = leftNode;
    struct ListNode* prev = NULL;

    // Reverse the portion of the list
    for (int i = 0; i <= right - left; i++) {
        struct ListNode* forw = current->next;
        current->next = prev;
        prev = current;
        current = forw;
    }

    leftTail->next = prev;
    leftNode->next = current;
    return dummy.next;
}

// Helper function to create a linked list from an array
struct ListNode* createLinkedList(int* values, int size) {
    if (size == 0) return NULL;

    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = values[0];
    head->next = NULL;

    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = values[i];
        current->next = NULL;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(struct ListNode* head) {
    printf("[");
    while (head) {
        printf("%d", head->val);
        if (head->next) {
            printf(",");
        }
        head = head->next;
    }
    printf("]\n");
}

// Main function to test the reverseBetween function
int main() {
    // Example 1
    int values1[] = {1, 2, 3, 4, 5};
    int left1 = 2, right1 = 4;
    struct ListNode* head1 = createLinkedList(values1, sizeof(values1) / sizeof(values1[0]));
    printf("Input: head = [1,2,3,4,5], left = %d, right = %d\n", left1, right1);
    struct ListNode* result1 = reverseBetween(head1, left1, right1);
    printf("Output: ");
    printLinkedList(result1);

    // Example 2
    int values2[] = {5};
    int left2 = 1, right2 = 1;
    struct ListNode* head2 = createLinkedList(values2, sizeof(values2) / sizeof(values2[0]));
    printf("Input: head = [5], left = %d, right = %d\n", left2, right2);
    struct ListNode* result2 = reverseBetween(head2, left2, right2);
    printf("Output: ");
    printLinkedList(result2);

    return 0;
}
