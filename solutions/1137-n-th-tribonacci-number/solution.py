@cache
def t(n):
    if n==0:
        return 0
    if n<3:
        return 1
    return t(n-1)+t(n-2)+t(n-3)
class Solution:
    def tribonacci(self, n: int) -> int:
        return t(n)