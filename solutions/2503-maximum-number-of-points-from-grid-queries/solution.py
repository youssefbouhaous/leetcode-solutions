import heapq
class Solution:
    def maxPoints(self, g: List[List[int]], q: List[int]) -> List[int]:
        ans = q.copy()
        ansd = [0]*(10**6+2)
        q.sort()
        h = []
        heapq.heappush(h,(g[0][0],0,0))
        n = len(g)
        m = len(g[0])
        vis = [[False]*m for _ in range(n)]
        cnt = 0
        d = [(1,0),(0,1),(-1,0),(0,-1)]
        def valid(i,j):
            return 0<=i< n and 0<=j<m
        maxh = 0
        while len(h)>0:
            v,x,y = heapq.heappop(h)
            cnt+=1
            vis[x][y] = True
            maxh = max(maxh,v)
            ansd[maxh]+=1
            for i,j in d:
                i+=x
                j+=y
                if valid(i,j) and not vis[i][j]:
                    vis[i][j] = True
                    heapq.heappush(h,(g[i][j],i,j))
        for i in range(1,len(ansd)):
            ansd[i] += ansd[i-1]
        for i in range(len(ans)):
            ans[i] = ansd[ans[i]-1]
        return ans
                
