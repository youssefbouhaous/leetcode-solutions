from collections import deque
class Solution:
    def pacificAtlantic(self, h: List[List[int]]) -> List[List[int]]:
        n = len(h)
        m = len(h[0])
        q = deque()
        isp = [[False]*m for _ in range(n)]
        isa = [[False]*m for _ in range(n)]
        for j in range(m):
            isp[0][j] = True
            isa[n-1][j] = True
            q.append((0,j))
            q.append((n-1,j))
        for i in range(n):
            q.append((i,0))
            q.append((i,m-1))
            isp[i][0] = True
            isa[i][m-1] = True
        def valid(i,j):
            return 0<=i<n and 0<=j<m
        while len(q)>0:
            x,y = q.popleft()
            d = [(1,0),(0,1),(-1,0),(0,-1)]
            for i,j in d:
                if (not valid(i+x,j+y)) or h[x][y]>h[x+i][y+j]:
                    continue
                if isp[x][y] and not isp[x+i][y+j]:
                        isp[x+i][y+j] = True
                        q.append((x+i,y+j))
                if isa[x][y] and not isa[x+i][y+j]:
                        isa[x+i][y+j] = True
                        q.append((x+i,y+j))
        ans = []
        for i in range(n):
            for j in range(m):
                if isp[i][j] and isa[i][j]:
                    ans.append((i,j))
        return ans