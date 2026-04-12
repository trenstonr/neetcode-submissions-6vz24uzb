class Solution {
    vector<vector<int>> res;
    vector<int> nums;
    int target;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;

        vector<int> curr;
        backtrack(0, 0, curr);
        
        return res;
    }
private:
    void backtrack(int start, int total, vector<int> &curr) {
        if (total > target) return;
        if (total == target) {
            res.push_back(curr);
            return;
        }
        if (start > nums.size() - 1) return;

        curr.push_back(nums[start]);
        backtrack(start, total + nums[start], curr);
        curr.pop_back();
        backtrack(start + 1, total, curr);
    }
};
