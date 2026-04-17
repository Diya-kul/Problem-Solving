/*
PROBLEM STATEMENT-
    LC-206. Reverse Linked List

    Given the head of a singly linked list, reverse the list, and return the reversed list.

    Example 1:
        Input: head = [1,2,3,4,5]
        Output: [5,4,3,2,1]

    Example 2:
        Input: head = [1,2]
        Output: [2,1]

    Example 3:
        Input: head = []
        Output: []

    Constraints:
        The number of nodes in the list is the range [0, 5000].
        -5000 <= Node.val <= 5000
 
*/
// SOLUTION:-
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Helper to insert new node at head
    ListNode* insertNew(ListNode* currentHead, int val){
        ListNode* newHead = new ListNode(val);
        newHead->next = currentHead;   // Link old list
        return newHead;                // Return new head
    }

    // Reverse list by building a new one
    ListNode* reverseList(ListNode* head) {
        ListNode* RList = NULL;   // Start with empty reversed list
        while(head != NULL){
            RList = insertNew(RList, head->val);
            head = head->next;
        }
        return RList;
    }
};

// Utility function to print a linked list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val;
        if(head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create a linked list from array
ListNode* createList(int arr[], int n) {
    if(n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for(int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example input
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Create original list
    ListNode* head = createList(arr, n);

    cout << "Original List: ";
    printList(head);

    // Reverse using Solution class
    Solution sol;
    ListNode* reversed = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(reversed);

    return 0;
}
