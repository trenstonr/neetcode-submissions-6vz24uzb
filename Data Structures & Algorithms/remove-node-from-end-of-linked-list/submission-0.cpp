/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1,2,3,4,5,6  n = 5
        ListNode dummy = ListNode(0, head);

        ListNode *first = &dummy, *second = &dummy;
        for (int i = 0; i < n; i++) {
            second = second->next;
        }

        while (second->next) {
            first = first->next;
            second = second->next;
        }

        if (!first->next) first->next = nullptr;
        else first->next = first->next->next;

        return dummy.next;
    }
};
