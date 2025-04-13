class Solution:
    def maximalSquare(self, mt: List[List[str]]) -> int:
        n=len(mt[0])
        m=len(mt)
        for i in range(m):
            for j in range(n):
                mt[i][j]=int(mt[i][j])
        for j in range(1,n):
            for i in range(1,m):
                if mt[i][j]!=0:
                    mt[i][j]=(mt[i][j])+(min(mt[i-1][j],mt[i][j-1],mt[i-1][j-1]))
        mx=0
        for i in mt:
            mx=max(mx,(max(i)))
        return mx*mx