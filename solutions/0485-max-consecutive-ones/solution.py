class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        mx = 0
        c = 0
        n = len(nums)
        for i in range(n):
            if nums[i] == 1:
                c += 1
            if c > mx:
                mx = c
            if nums[i] == 0:
                c = 0
        return mx