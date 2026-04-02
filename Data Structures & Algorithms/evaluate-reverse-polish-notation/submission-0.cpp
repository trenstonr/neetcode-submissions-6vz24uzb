class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (const string& t : tokens) {
            if (!(t == "+" || t == "-" || t == "*" || t == "/")) { // <algorithm>
                stk.push(stoi(t)); // <string>
                continue;
            }

            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();

            if (t == "+") stk.push(a + b);
            else if (t == "-") stk.push(a - b);
            else if (t == "*") stk.push(a * b);
            else stk.push(a / b);
        }

        return stk.top();
    }
};
