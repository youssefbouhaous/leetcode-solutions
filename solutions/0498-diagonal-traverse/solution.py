class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        l = []
        i = 0
        j = 0
        n = len(mat)
        m = len(mat[0])
        def isValid(i, j):
            return 0 <= i < n and 0 <= j < m
        d =  -1
        while len(l)<n*m:
            l.append(mat[i][j])
            if isValid(i+d,j-d):
                i+=d
                j-=d
            else:
                if d==-1:
                    j+=1
                    if j>=m:
                        j=m-1
                        i+=1
                else:
                    i+=1
                    if i>=n:
                        i=n-1
                        j+=1
                d*=-1
        return l 