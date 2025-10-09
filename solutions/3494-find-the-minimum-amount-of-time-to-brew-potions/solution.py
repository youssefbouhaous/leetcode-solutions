class Solution:
    def minTime(self, s: List[int], ma: List[int]) -> int:
        n = len(s)
        m = len(ma)
        pre = [0]*n
        for j in range(m):
            ans = 0
            for i in range(n):
                ans = max(ans,pre[i])+s[i]*ma[j]
            pre[n-1] = ans
            for i in range(n-2,-1,-1):
                pre[i] = pre[i+1]-s[i+1]*ma[j]
        return pre[n-1]
        