class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, wild;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') wild.push(i);
            else if (s[i] == '(') open.push(i);
            else {
                if (open.empty() && wild.empty()) return false;
                if (!open.empty()) open.pop();
                else wild.pop();
            }
        }

        if (open.size() > wild.size()) return false;

        while (!open.empty()) {
            int i = open.top(), j = wild.top();
            open.pop(); wild.pop();
            if (i > j) return false;
        }

        return true;
    }
};
