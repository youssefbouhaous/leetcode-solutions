class Solution:
    def sumAndMultiply(self, n: int) -> int:
        p = '0'
        s = 0
        for i in str(n):
            if i != '0':
                p = p+i
                s += int(i)
        return s*int(p)