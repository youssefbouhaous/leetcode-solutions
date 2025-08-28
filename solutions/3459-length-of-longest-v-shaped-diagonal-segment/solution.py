class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        @cache
        def isValid(i,j):
            return 0<=i<Solution.n and 0<=j<Solution.m
        @cache
        def f(i,j,case,rot,d):
            xy = []
            if d == 1:
                xy = [(i+1,j+1,0,1),(i+1,j-1,1,2)]
            if d == 2:
                xy = [(i+1,j-1,0,2),(i-1,j-1,1,3)]
            if d == 3:
                xy = [(i-1,j-1,0,3),(i-1,j+1,1,4)]
            if d == 4:
                xy = [(i-1,j+1,0,4),(i+1,j+1,1,1)]  
            mx = 1
            if case == 2:
                for c in xy:
                    if ( isValid(c[0],c[1])) and rot+c[2] <2 and grid[c[0]][c[1]]==0:
                        mx = max(mx,1 + f(c[0],c[1],0,rot+c[2],c[3]))
            if case == 0:
                for c in xy:
                    if ( isValid(c[0],c[1])) and rot+c[2] <2 and grid[c[0]][c[1]]==2:
                        mx = max(mx,1 + f(c[0],c[1],2,rot+c[2],c[3]))
            return mx
        mx = 0
        Solution.n = len(grid)
        Solution.m = len(grid[0])
        
        for i in range(Solution.n):
            for j in range(Solution.m):
                if grid[i][j] == 1:
                    mx=max(1,mx)
                    if isValid(i+1,j+1) and grid[i+1][j+1]==2:
                        mx=max(mx,1+f(i+1,j+1,2,0,1))
                    if isValid(i+1,j-1) and grid[i+1][j-1]==2:
                        mx=max(mx,1+f(i+1,j-1,2,0,2))
                    if isValid(i-1,j-1) and grid[i-1][j-1]==2:
                        mx=max(mx,1+f(i-1,j-1,2,0,3))
                    if isValid(i-1,j+1) and grid[i-1][j+1]==2:
                        mx=max(mx,1+f(i-1,j+1,2,0,4))
        return mx