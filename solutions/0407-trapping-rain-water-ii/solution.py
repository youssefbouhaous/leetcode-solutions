import heapq
class Solution:
    def trapRainWater(self, l: List[List[int]]) -> int:
        h = []
        n = len(l)
        m = len(l[0])
        vis = [[False]*m for _ in range(n)]
        for i in range(n):
            heapq.heappush(h,(l[i][0],i,0))
            heapq.heappush(h,(l[i][m-1],i,m-1))
        for j in range(m):
            heapq.heappush(h,(l[0][j],0,j))
            heapq.heappush(h,(l[n-1][j],n-1,j))
        maxh = 0
        ans = 0
        d = [(1,0),(0,1),(-1,0),(0,-1)]
        def valid(i,j):
            return 0<=i<n and 0<=j<m
        while len(h)>0:
            v,x,y = heapq.heappop(h)
            maxh = max(maxh,v)
            vis[x][y] = True
            ans += maxh - v
            for i,j in d:
                i += x
                j += y
                if valid(i,j) and not vis[i][j]:
                    heappush(h,(l[i][j],i,j))
                    vis[i][j] = True
        return ans