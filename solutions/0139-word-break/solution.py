class Solution:
    def wordBreak(self, s: str, w: List[str]) -> bool:
        n=len(s)
        dp=[False]*(n+1)
        for i in w:
            if s[0]==i[0] and len(i)<=n:
                if s.startswith(i):
                    dp[len(i)]=True
        for i in range(1,n):
            if dp[i]==True:
                for x in w:
                    if s[i:].startswith(x):
                        dp[i+len(x)]=True
        return dp[n]