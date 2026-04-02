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
#define pii pair<int, int>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int n = lists.size();

        ListNode dummy = ListNode();
        ListNode* curr = &dummy;

        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        for (int i = 0; i < n; i++) {
            if (lists[i]) minHeap.push({lists[i]->val, i});
        }

        while (!minHeap.empty()) {
            auto [_, i] = minHeap.top();
            minHeap.pop();

            curr->next = lists[i];
            curr = curr->next;
            lists[i] = lists[i]->next;

            if (lists[i]) minHeap.push({lists[i]->val, i});
        }

        return dummy.next;
    }
};
