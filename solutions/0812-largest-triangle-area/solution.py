class Solution:
    def largestTriangleArea(self, p: List[List[int]]) -> float:
        n = len(p)
        ans = 0
        for i in range(n):
            for j in range(i+1,n):
                for k in range(j+1,n):
                    x1 = p[i][0]
                    x2 = p[j][0]
                    x3 = p[k][0]
                    y1 = p[i][1]
                    y2 = p[j][1]
                    y3 = p[k][1]
                    s =  abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))/2
                    ans = max(ans,s)
        return ans