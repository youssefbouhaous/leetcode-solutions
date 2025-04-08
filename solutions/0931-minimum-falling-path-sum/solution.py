class Solution:
    def minFallingPathSum(self, mt: List[List[int]]) -> int:
        n=len(mt)
        m=len(mt[0])
        dp=[[math.inf]*(m) for i in range(n)]
        dp[0]=mt[0]
        for i in range(n-1):
            for j in range(m):
                l=max(0,j-1)
                r=min(m-1,j+1)
                dp[i+1][l]=min(dp[i+1][l],dp[i][j]+mt[i+1][l])
                dp[i+1][r]=min(dp[i+1][r],dp[i][j]+mt[i+1][r])
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+mt[i+1][j])
        return min(dp[n-1])