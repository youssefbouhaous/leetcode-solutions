class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        for i in range(n):
            if sorted(nums[i:i+k]) == nums[i:i+k] and len(set(nums[i:i+k])) == k and len(set(nums[i+k:i+2*k])) == k and sorted(nums[i+k:i+2*k]) == nums[i+k:i+2*k]:
                return True
        return False