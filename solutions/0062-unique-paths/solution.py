@cache
def f(i,j,n,m):
    if i==n and j==m:
        return 1
    if i>n or j>m:
        return 0
    return f(i+1,j,n,m)+f(i,j+1,n,m)
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return f(1,1,n,m)