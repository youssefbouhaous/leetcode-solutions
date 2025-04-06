class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:
            return nums[0]
        l=nums
        dp=[0]*n
        dp[0]=l[0]
        dp[1]=max(l[1],l[0])
        for i in range(2,n):
            dp[i]=max(l[i]+dp[i-2],dp[i-1])
        return max(dp[n-1],dp[n-2])