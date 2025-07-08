class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        n=len(matrix)
        for r,c in zip(matrix,zip(*matrix)):
            if len(set(r))!=n or len(set(c))!=n:
                return False
        return True
            