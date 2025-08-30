class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in board:
            for j in i:
                if j!="." and i.count(j)>1:
                    return False
        for col in zip(*board):
            for j in col:
                if j!="." and col.count(j)>1:
                    return False
        for i in range(3):
            for j in range(3):
                sub = board[i*3][j*3:j*3+3]+board[i*3+1][j*3:j*3+3]+board[i*3+2][j*3:j*3+3]
                for x in sub:
                    if x!="." and sub.count(x)>1:
                        return False
        return True