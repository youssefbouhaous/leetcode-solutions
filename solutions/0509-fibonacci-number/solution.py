@cache
def f(n):
    if n<2:
        return n
    return f(n-1)+f(n-2)
class Solution:
    def fib(self, n: int) -> int:
        return f(n)