class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        nums = sorted(nums)
        for i in range(len(nums)):
            if k == 0:
                break
            if nums[i]<0:
                nums[i] = -nums[i]
                k -= 1
            elif nums[i] == 0:
                return sum(nums)
            else:
                break
            
        if k%2==0:
            return sum(nums)
        else:
            return sum(nums)-2*min(nums)