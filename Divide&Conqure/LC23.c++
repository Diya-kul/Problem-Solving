/*
    PROBLEM STATMENT:- 23. Merge k Sorted Lists

        You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

        Merge all the linked-lists into one sorted linked-list and return it.

        

            Example 1:
                Input: lists = [[1,4,5],[1,3,4],[2,6]]
                Output: [1,1,2,3,4,4,5,6]
                Explanation: The linked-lists are:
                    [
                    1->4->5,
                    1->3->4,
                    2->6
                    ]
                    merging them into one sorted linked list:
                    1->1->2->3->4->4->5->6
            Example 2:
                Input: lists = []
                Output: []
            Example 3:
                Input: lists = [[]]
                Output: []
*/
// Solution
# include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a && b) {

            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        tail->next = a ? a : b;

        return dummy.next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) {
            return nullptr;
        }

        int interval = 1;

        while (interval < lists.size()) {

            for (int i = 0;
                 i + interval < lists.size();
                 i += interval * 2) {

                lists[i] = mergeTwoLists(
                    lists[i],
                    lists[i + interval]
                );
            }

            interval *= 2;
        }

        return lists[0];
    }
};