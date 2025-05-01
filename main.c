#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (left == right)
        return head;

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* leftTail = &dummy;
    struct ListNode* leftNode = head;

    for (int i = 1; i < left; i++) {
        leftTail = leftTail->next;
        leftNode = leftNode->next;
    }

    struct ListNode* current = leftNode;
    struct ListNode* prev = NULL;

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
struct ListNode* createList(int* vals, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = vals[0];
    head->next = NULL;
    struct ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = vals[i];
        current->next = NULL;
    }
    return head;
}

// Helper function to print a linked list
void printList(struct ListNode* head) {
    printf("[");
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(",");
        head = head->next;
    }
    printf("]");
}

// Helper function to delete a linked list
void deleteList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Example 1
    int vals1[] = {1, 2, 3, 4, 5};
    struct ListNode* head1 = createList(vals1, 5);
    printf("Input: head = [1,2,3,4,5], left = 2, right = 4\n");
    struct ListNode* result1 = reverseBetween(head1, 2, 4);
    printf("Output: ");
    printList(result1);
    printf("\n");
    deleteList(result1);

    // Example 2
    int vals2[] = {5};
    struct ListNode* head2 = createList(vals2, 1);
    printf("Input: head = [5], left = 1, right = 1\n");
    struct ListNode* result2 = reverseBetween(head2, 1, 1);
    printf("Output: ");
    printList(result2);
    printf("\n");
    deleteList(result2);

    return 0;
}
