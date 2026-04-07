class Solution {
    vector<vector<int>> res;
    vector<int> nums;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        vector<int> curr;
        backtrack(0, curr);
        return res;
    }
private:
    void backtrack(int start, vector<int>& curr) {
        res.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(i + 1, curr);
            curr.pop_back();
        }
    }
};
