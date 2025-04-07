class Solution:
    def uniquePathsWithObstacles(self, o: List[List[int]]) -> int:
        m=len(o)
        n=len(o[0])
        @cache
        def f(i,j):
            if i==0 and j==0:
                return (1 if o[i][j]==0 else 0)
            if i<0 or j<0:
                return 0
            if o[i][j]==1:
                return 0
            return f(i-1,j)+f(i,j-1)
        return f(m-1,n-1)