import heapq
class Solution:
    def trap(self, l: List[int]) -> int:
        h = []
        n = len(l)
        if n<3:
            return 0
        heapq.heappush(h,(l[0],0))
        heapq.heappush(h,(l[n-1],n-1))
        vis = [False]*n
        maxh = 0
        ans = 0
        d = [1,-1]
        while len(h)>0:
            v,x=heapq.heappop(h)
            maxh = max(maxh,v)
            vis[x] = True
            ans += maxh - v
            for i in d:
                i += x
                if 0<=i<n and not vis[i]:
                    vis[i]=True
                    heapq.heappush(h,(l[i],i))
        return ans