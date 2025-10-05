import heapq
class Solution:
    def pacificAtlantic(self, h: List[List[int]]) -> List[List[int]]:
        n = len(h)
        m = len(h[0])
        atl = [[False]*m for _ in range(n)]
        pac = [[False]*m for _ in range(n)]
        vis = [[False]*m for _ in range(n)]
        def valid(i,j):
            return 0<=i<n and 0<=j<m
        ans = set()
        d = [(1,0),(0,1),(-1,0),(0,-1)]
        def dfs(i,j):
            if not valid(i,j):
                return
            if atl[i][j] and pac[i][j]:
                ans.add((i,j))
            vis[i][j] = True
            maxh = []
            tmp = []
            for x,y in d:
                if valid(x+i,y+j):
                    heapq.heappush(maxh,(-h[x+i][y+j],i+x,j+y))
                    tmp.append((i+x,j+y))
            while len(maxh)>0:
                o,x,y = heapq.heappop(maxh)
                x -= i
                y -= j
                if  not vis[x+i][y+j]:
                    dfs(i+x,y+j)
                if h[i][j]>=h[i+x][j+y]:
                    pac[i][j] = pac[i][j] or pac[i+x][j+y]
                    atl[i][j] = atl[i][j] or atl[i+x][j+y]
                if h[i][j]<=h[i+x][j+y]:
                    pac[i+x][j+y] = pac[i+x][j+y] or pac[i][j]
                    atl[i+x][j+y] = atl[i+x][j+y] or atl[i][j]
                if pac[i][j] and atl[i][j]:
                    ans.add((i,j))
                if pac[i+x][j+y] and atl[i+x][j+y]:
                    ans.add((i+x,j+y))
            for x,y in tmp:
                x-= i
                y -= j
                if h[i][j]<= h[i+x][j+y]:
                    pac[i+x][j+y] = pac[i+x][j+y] or pac[i][j]
                    atl[i+x][j+y] = atl[i+x][j+y] or atl[i][j]
                if pac[i][j] and atl[i][j]:
                    ans.add((i,j))
                if pac[i+x][j+y] and atl[i+x][j+y]:
                    ans.add((i+x,j+y))
        for i in range(n):
            pac[i][0] = True
            atl[i][m-1] = True
        for j in range(m):
            pac[0][j] = True
            atl[n-1][j] = True
        maxh = []
        for i in range(n):
            for j in range(m):
                heapq.heappush(maxh,(-h[i][j],i,j))
        while len(maxh)>0:
            o,x,y = heapq.heappop(maxh)
            dfs(x,y)
        for i in range(n):
            for j in range(m):
                dfs(i,j)
                if pac[i][j] and atl[i][j]:
                    ans.add((i,j))
        
        return list(ans)