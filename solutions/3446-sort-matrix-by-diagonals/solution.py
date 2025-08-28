class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        m = len(grid[0])
        for i in range(n):
            tmp = []
            x = i
            y = 0
            while x<n and y<m:
                tmp.append(grid[x][y])
                x+=1
                y+=1
            tmp.sort(reverse=True)
            x = i
            y = 0
            while x<n and y<m:
                grid[x][y] = tmp[y]
                x+=1
                y+=1
        for j in range(1,m):
            tmp = []
            x = 0
            y = j
            while x<n and y<m:
                tmp.append(grid[x][y])
                x+=1
                y+=1
            tmp.sort()
            x = 0
            y = j
            while x<n and y<m:
                grid[x][y] = tmp[x]
                x+=1
                y+=1
        return grid
            