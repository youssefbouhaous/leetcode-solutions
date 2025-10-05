import heapq
class Solution:
    def trap(self, h: List[int]) -> int:
        n = len(h)
        pre = [0]*n
        suf = [0]*n
        pre[0] = h[0]
        suf[n-1] = h[n-1]
        for i in range(1,n):
            pre[i] = max(pre[i-1],h[i])
        for i in range(n-2,-1,-1):
            suf[i] = max(suf[i+1],h[i])
        ans = 0
        for i in range(1,n-1):
            ans += max(0,min(pre[i-1],suf[i+1])-h[i])
        return ans