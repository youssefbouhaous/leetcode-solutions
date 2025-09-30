import math
class Solution:
    def minScoreTriangulation(self, l: List[int]) -> int:
        @cache
        def f(i,j):
            if j-i<2:
                return 0
            ans = math.inf
            for k in range(i+1,j):
                ans = min(ans,f(i,k)+f(k,j)+l[i]*l[k]*l[j])
            return ans
        return f(0,len(l)-1)
