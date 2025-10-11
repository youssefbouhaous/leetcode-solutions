from collections import defaultdict
class Solution:
    def maximumTotalDamage(self, p: List[int]) -> int:
        d = defaultdict(int)
        for i in p:
            d[i] += 1
        l = []
        for o in d:
            l.append((o,d[o]*o))
            d[o] = d[o]*o
        l.sort()
        n = len(l)
        for i in range(n):
            tmp = []
            nn = [k+l[i][0] for k in range(-2,3)]
            for j in range(1,4):
                if i-j>=0 and l[i-j][0] not in nn:
                    tmp.append(d[l[i-j][0]])
            if len(tmp)>0:
                d[l[i][0]] += max( tmp)
            for j in range(4):
                if i-j>=0:
                    d[l[i][0]] = max(d[l[i-j][0]],d[l[i][0]])
        return max(d.values())