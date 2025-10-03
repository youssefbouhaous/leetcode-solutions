import heapq

class Solution:
    class C:
        def __init__(self, h, i, j):
            self.h = h
            self.i = i
            self.j = j
        def __lt__(self, o):
            return self.h < o.h

    def v(self, i, j, n, m):
        return 0 <= i < n and 0 <= j < m

    def trapRainWater(self, l):
        d = [(1,0),(-1,0),(0,1),(0,-1)]
        n = len(l)
        m = len(l[0])
        vis = [[False]*m for _ in range(n)]
        h = []
        for i in range(n):
            heapq.heappush(h, self.C(l[i][0], i, 0))
            heapq.heappush(h, self.C(l[i][m-1], i, m-1))
            vis[i][0] = vis[i][m-1] = True
        for j in range(m):
            heapq.heappush(h, self.C(l[0][j], 0, j))
            heapq.heappush(h, self.C(l[n-1][j], n-1, j))
            vis[0][j] = vis[n-1][j] = True
        ans = 0
        while h:
            o = heapq.heappop(h)
            for x,y in d:
                ni, nj = o.i+x, o.j+y
                if self.v(ni, nj, n, m) and not vis[ni][nj]:
                    vis[ni][nj] = True
                    if l[ni][nj] < o.h:
                        ans += o.h - l[ni][nj]
                    heapq.heappush(h, self.C(max(l[ni][nj], o.h), ni, nj))
        return ans
