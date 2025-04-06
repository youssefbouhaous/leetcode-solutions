class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        from collections import defaultdict
        oc = defaultdict(int)
        dp=defaultdict(int)
        for i in nums:
            oc[i]=oc[i]+1
        ans=0
        for i in range(20001):
            dp[i]=max(oc[i]*i+dp[i-2],dp[i-1])
            #print(i,dp[i])
            ans=max(ans,dp[i]) 
        return ans