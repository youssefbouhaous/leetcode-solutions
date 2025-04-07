import math

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])

        @cache
        def f(i, j):
            if i > 0 and j > 0:
                return grid[i][j] + min(f(i - 1, j), f(i, j - 1))
            elif i > 0:
                return grid[i][j] + f(i - 1, j)
            elif j > 0:
                return grid[i][j] + f(i, j - 1)
            return grid[i][j]

        return f(n - 1, m - 1)