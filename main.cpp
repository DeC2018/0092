#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1)
            return reverseN(head, right);

        head->next = reverseBetween(head->next, left - 1, right - 1);

        return head;
    }

private:
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            successor = head->next;
            return head;
        }

        ListNode* newHead = reverseN(head->next, n - 1);
        ListNode* headNext = head->next;
        head->next = headNext->next;
        headNext->next = head;

        return newHead;
    }

    ListNode* successor = nullptr; // To keep track of the node after the reversed section
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) {
            cout << ",";
        }
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    // Example 1
    vector<int> values1 = {1, 2, 3, 4, 5};
    int left1 = 2, right1 = 4;
    ListNode* head1 = createLinkedList(values1);
    cout << "Input: head = [1,2,3,4,5], left = " << left1 << ", right = " << right1 << endl;
    ListNode* result1 = solution.reverseBetween(head1, left1, right1);
    cout << "Output: ";
    printLinkedList(result1);

    // Example 2
    vector<int> values2 = {5};
    int left2 = 1, right2 = 1;
    ListNode* head2 = createLinkedList(values2);
    cout << "Input: head = [5], left = " << left2 << ", right = " << right2 << endl;
    ListNode* result2 = solution.reverseBetween(head2, left2, right2);
    cout << "Output: ";
    printLinkedList(result2);

    return 0;
}
