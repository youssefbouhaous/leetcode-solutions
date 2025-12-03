class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        if k<n:
            return k
        d = 1
        i = 0
        while k>0:
            i += d
            k -= 1
            if i==n:
                i = n-2
                d=-1
            elif i == -1:
                i = 1
                d = 1
        return i