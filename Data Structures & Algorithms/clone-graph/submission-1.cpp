/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        return clone(node);
    }
private:
    unordered_map<Node*, Node*> nodeToCopy;

    Node* clone(Node* node) {
        if (!node) return nullptr;
        if (nodeToCopy.count(node)) return nodeToCopy[node];

        Node* clone = new Node(node->val);
        nodeToCopy[node] = clone;

        for (Node* nei : node->neighbors) {
            clone->neighbors.push_back(this->clone(nei));
        }

        return clone;
    }
};
