class Solution:
    def compareVersion(self, a: str, b: str) -> int:
        a = a.split('.')
        b = b.split('.')
        n = len(a)
        m = len(b)
        o = max(n,m)
        a = a + [0]*(o-n)
        b = b + [0]*(o-m)
        for i,j in zip(a,b):
            i = int(i)
            j = int(j)
            if i < j:
                return -1
            elif i>j:
                return 1
        return 0