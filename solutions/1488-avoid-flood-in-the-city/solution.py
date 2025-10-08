import heapq
class Solution:
    def avoidFlood(self, r: List[int]) -> List[int]:
        n = len(r)
        d = {}
        ans = []
        d[0] = []
        for i in range(n):
            if r[i] == 0:
                ans.append(1)
                heapq.heappush(d[0],i)
            else:
                ans.append(-1)
                if r[i] not in d:
                    d[r[i]] = i
                    continue
                f = False
                tmp = []
                while len(d[0])>0:
                    o = heapq.heappop(d[0])
                    if o > d[r[i]]:
                        ans[o] = r[i]
                        f = True
                        break
                    tmp.append(o)
                if not f:
                    return []
                for a in tmp:
                    heapq.heappush(d[0],a)
                d[r[i]] = i
        return ans