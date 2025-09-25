import math
class Solution:
    def minimumTotal(self, t: List[List[int]]) -> int:
        n = len(t)
        dp =[[math.inf]*n for _ in range(n)]
        dp[0][0] = t[0][0]
        for i in range(1,n):
            dp[i][0] = t[i][0] + dp[i-1][0]
            for j in range(1,i):
                dp[i][j] = t[i][j]+min(dp[i-1][j],dp[i-1][j-1])
            dp[i][i] = t[i][i] + dp[i-1][i-1]
        return min(dp[n-1])