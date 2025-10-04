class Solution:
    def maxArea(self, h: List[int]) -> int:
        n = len(h)
        l = 0
        r = n-1
        ans = 0
        while l<r:
            tmp = (r-l)*min(h[l],h[r])
            ans = max(ans,tmp)
            if h[r]>h[l]:
                l+=1
            else:
                r-=1
        return ans