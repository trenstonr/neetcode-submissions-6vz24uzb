class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if (n == 0) return 1;
        if (s[0] == '0') return 0;
        if (n == 1) return 1;

        int first = (s[n - 1] != '0' ? 1 : 0), second = 1;

        for (int i = n - 2; i >= 0; i--) {
            int next = 0;

            if (s[i] != '0') {
                next = first;
                if (i + 1 < n && isValidTwo(s[i], s[i + 1]))
                    next += second;
            }
            
            second = first;
            first = next;
        }

        return first;

    }

private:
    bool isValidTwo(char a, char b) {
        int two = (a - '0')*10 + (b - '0');
        return (two >= 10 && two <= 26);
    }
};
