import heapq
class Solution:
    def trapRainWater(self, l: List[List[int]]) -> int:
        vis = {}
        n = len(l)
        m = len(l[0])
        ans = 0
        def valid(i,j):
            return 0<=i<n and 0<=j<m
        d = [(1,0),(0,1),(-1,0),(0,-1)]
        h = []
        for i in range(n):
            heapq.heappush(h,(l[i][0],(i,0)))
            heapq.heappush(h,(l[i][m-1],(i,m-1)))
            vis[(i,0)] = True 
            vis[(i,m-1)] = True 
        for i in range(m):
            heapq.heappush(h,(l[0][i],(0,i)))
            heapq.heappush(h,(l[n-1][i],(n-1,i)))
            vis[(0,i)] = True 
            vis[(n-1,i)] = True
        mx = -1 
        while len(h)>0:
            o = heapq.heappop(h)
            hh = o[0]
            i,j = o[1]
            mx =max(mx,hh)
            ans += mx - hh
            vis[(i,j)] = True
            for x,y in d:
                if valid(x+i,y+j) and (x+i,y+j) not in vis:
                    #ans += max(0,l[i][j]-l[x+i][y+j])
                    vis[(x+i,y+j)] = True   
                    heapq.heappush(h,(l[x+i][y+j],(x+i,y+j)))
        return ans
                