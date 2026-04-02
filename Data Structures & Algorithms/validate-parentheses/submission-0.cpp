class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> c_to_o = {
            {'}', '{'},
            {')', '('},
            {']', '['}
        };

        stack<char> stk;
        for (char c : s) {
            if (!c_to_o.count(c)) {
                stk.push(c);
                continue;
            };
            
            if (stk.empty()) return false;
            if (stk.top() != c_to_o[c]) return false;

            stk.pop();
        }

        if (!stk.empty()) return false;
        return true;
    }
};
