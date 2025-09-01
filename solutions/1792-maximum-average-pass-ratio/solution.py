import heapq
def gain(l):
    a,b=l[0],l[1]
    return (b-a)/(b**2+b)
class Solution:
    def maxAverageRatio(self, c: List[List[int]], e: int) -> float:
        ans = 0
        pq = []
        for i in c:
            heapq.heappush(pq,[-gain(i),i])
        for i in range(e):
            tmp = heapq.heappop(pq)
            x,y=tmp[1]
            x+=1
            y+=1
            tmp=[-gain([x,y]),[x,y]]
            heapq.heappush(pq, tmp)
        for i in pq:
            ans += i[1][0]/i[1][1]
        return ans/len(c)