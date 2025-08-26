class Solution:
    def areaOfMaxDiagonal(self, d: List[List[int]]) -> int:
        ans = 0
        dmax = 0
        for i in d:
            if dmax < i[0]**2 + i[1]**2:
                dmax = i[0]**2 + i[1]**2
                ans = i[0]*i[1]
            elif dmax == i[0]**2 + i[1]**2:
                ans = max(ans,i[0]*i[1])
        return ans