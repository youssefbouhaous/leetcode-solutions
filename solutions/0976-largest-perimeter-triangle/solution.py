class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums = sorted(nums)
        n = len(nums)
        mans = 0
        for i in range(2,n):
            l = i-2
            r = i-1
            if nums[l]+nums[r]>nums[i]:
                mans = max(mans,nums[l]+nums[r]+nums[i])
        return mans