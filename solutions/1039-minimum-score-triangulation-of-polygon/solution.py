class Solution:
    def minScoreTriangulation(self, l: List[int]) -> int:
        ans = 0
        n = len(l)
        dp = [[math.inf]*(n+1) for _ in range(n+1)]
        def f(i,j):
            if dp[i][j] != math.inf:
                return dp[i][j]
            if j-i<2:
                return 0
            ans =math.inf
            for k in range(i+1,j):
                ans = min(ans,f(i,k)+f(k,j)+l[i]*l[k]*l[j])
            dp[i][j]=ans
            return ans
        return f(0,n-1)