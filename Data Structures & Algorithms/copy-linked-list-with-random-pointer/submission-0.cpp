/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        return rcopy(head, mp);
    }
private:
    Node* rcopy(Node* node, unordered_map<Node*, Node*>& mp) {
        if (!node) return nullptr;
        if (mp.count(node)) return mp[node];

        Node* copy = new Node(node->val);
        mp[node] = copy;
        copy->next = rcopy(node->next, mp);
        copy->random = rcopy(node->random, mp);

        return copy;
    }
};
