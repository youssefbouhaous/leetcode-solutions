class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        while len(nums)>3:
            l = []
            n = len(nums)
            for i in range(0,n,4):
                l.append(min(nums[i],nums[i+1]))
                l.append(max(nums[i+2],nums[i+3]))
            nums = l
        if len(nums)==1:
            return nums[0]
        if len(nums)<4:
            return min(nums[0],nums[1])
        return min(min(nums[0],nums[1]),max(nums[2],nums[3]))