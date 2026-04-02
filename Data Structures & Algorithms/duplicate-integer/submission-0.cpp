class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int n : nums) {
            if (!seen.count(n)) seen.insert(n);
            else return true;
        }
        return false;
    }
};