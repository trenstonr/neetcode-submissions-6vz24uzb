class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        curr = []
        self.backtrack(0, curr, res, nums)
        return res

    def backtrack(self, start, curr, res, nums):
        res.append(curr.copy())
        for i in range(start, len(nums)):
            curr.append(nums[i])
            self.backtrack(i + 1, curr, res, nums)
            curr.pop()