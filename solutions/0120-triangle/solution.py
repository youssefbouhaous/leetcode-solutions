class Solution:
    def minimumTotal(self, t: List[List[int]]) -> int:
        n=len(t)
        m=len(t[-1])
        dp=[[10001]*(m+1) for i in range(n+1)]
        dp[0][0]=t[0][0]
        for i in range(n-1):
            for j in range(len(t[i])):
                dp[i+1][j]=min(dp[i+1][j],t[i+1][j]+dp[i][j])
                dp[i+1][j+1]=min(dp[i+1][j+1],t[i+1][j+1]+dp[i][j])
        ans=min(dp[-2])
        return ans