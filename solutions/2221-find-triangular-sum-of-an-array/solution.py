import math
class Solution:
    def triangularSum(self, l: List[int]) -> int:
        while len(l)>1:
            h = []
            for i in range(len(l)-1):
                h.append((l[i]+l[i+1])%10)
            l = h
        return l[0]