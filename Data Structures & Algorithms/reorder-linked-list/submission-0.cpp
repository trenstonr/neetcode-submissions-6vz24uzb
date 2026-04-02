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
    void reorderList(ListNode* head) {
        if (!head) return;

        ListNode dummy = ListNode();
        dummy.next = head;

        ListNode *first = head, *second = head;
        while (second->next && second->next->next) {
            first = first->next;
            second = second->next->next;
        }

        second = first->next;
        first->next = nullptr;
        first = nullptr;

        while (second) {
            ListNode* temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }

        second = first;
        first = dummy.next;
        ListNode* curr = &dummy;

        while (first && second) {
            ListNode* next1 = first->next;
            ListNode* next2 = second->next;

            curr->next = first;
            curr = curr->next;

            curr->next = second;
            curr = curr->next;

            first = next1;
            second = next2;
        }

        if (first) curr->next = first;
    }
};
