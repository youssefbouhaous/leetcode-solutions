import heapq
class Solution:
    def swimInWater(self, g: List[List[int]]) -> int:
        n = len(g)
        h = []
        heapq.heappush(h,(g[0][0],0,0))
        maxh = 0
        d = [(1,0),(0,1),(-1,0),(0,-1)]
        vis = [[False]*n for _ in range(n)]
        def valid(i,j):
            return 0<=i<n and 0<=j<n
        while len(h)>0:
            v,x,y = heapq.heappop(h)
            vis[x][y] = True
            maxh = max(maxh,v)
            if x ==  n-1 and y == n-1:
                return maxh
            for i,j in d:
                i += x
                j += y
                if valid(i,j) and not vis[i][j]:
                    heapq.heappush(h,(g[i][j],i,j))
        return maxh