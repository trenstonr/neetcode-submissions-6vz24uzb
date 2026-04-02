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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int n = lists.size();

        ListNode dummy = ListNode();
        ListNode* curr = &dummy;

        while (true) {
            int empty = 0;

            int min = -1;
            for (int i = 0; i < n; i++) {
                if (lists[i] == nullptr) {
                    empty++;
                    continue;
                }

                if ((min == -1 && lists[i]) || (lists[i]->val < lists[min]->val)) {
                    min = i;
                }
            }

            if (empty == n) break;

            curr->next = lists[min];
            curr = curr->next;
            lists[min] = lists[min]->next;
        }

        return dummy.next;
    }
};
