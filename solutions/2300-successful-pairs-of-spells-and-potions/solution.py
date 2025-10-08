class Solution:
    def successfulPairs(self, s: List[int], p: List[int], x: int) -> List[int]:
        p = sorted(p)
        ans = []
        n = len(p)
        for i in s:
            l = 0
            r = n-1
            a = math.inf
            while l<=r:
                m = (l+r)//2
                if i*p[m] >= x:
                    a = min(a,m)
                    r = m - 1
                else:
                    l = m + 1
            if a == math.inf:
                ans.append(0)
            else:
                ans.append(n-a)
        return ans 