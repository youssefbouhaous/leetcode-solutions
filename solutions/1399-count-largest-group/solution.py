from collections import defaultdict

class Solution:
    def countLargestGroup(self, n: int) -> int:
        d = defaultdict(list)
        mx = 0
        nb = 0
        for i in range(1,n+1):
            s = str(i)
            ss = 0
            for j in s:
                ss += int(j)
            d[ss].append(s)
        for j in d:
            if len(d[j]) > mx:
                mx = len(d[j])
                nb = 1
            elif len(d[j]) == mx:
                nb += 1
        return nb