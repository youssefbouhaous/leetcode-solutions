from math import log
class Solution:
    def minOperations(self, q: List[List[int]]) -> int:
        ans = 0
        for a,b in q:
            t = 0
            p = 1
            s = 0
            while p <= b:
                l = max(a,p)
                r = min(b, p*4 -1)
                if l <= r:
                    t+=(r-l+1)*(s+1)
                p *= 4
                s+=1
            ans += ceil(t/2)
        return ans