import heapq
class Solution:
    def avoidFlood(self, r: List[int]) -> List[int]:
        n = len(r)
        d = {}
        d[0] = []
        ans = []
        for i in range(n):
            if r[i] == 0:
                heapq.heappush(d[0],i)
                ans.append(1)
            else:
                ans.append(-1)
                if r[i] not in d:
                    d[r[i]] = i
                    continue
                if len(d[0])==0:
                    return []

                tmp = []
                f = False
                while len(d[0])>0:
                    
                    o = heapq.heappop(d[0])
                    if o > d[r[i]]:
                        d[r[i]] = i
                        ans[o] = r[i]
                        f = True
                        break
                    tmp.append(o)
                if not f:
                    return []
                for a in tmp:
                    heapq.heappush(d[0],a)  
        return ans