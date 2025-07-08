class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        n=len(matrix)
        l=[i for i in range(1,1+n)]
        for i in matrix:
            if sorted(i)!=l:
                return False
        for i in range(n):
            k=[]
            for j in range(n):
                k.append(matrix[j][i])
            if sorted(k)!=l:
                return False
        return True
            