
class Solution:
    from itertools import product
    
    d=set([str(num) for num in range(1,10)])
    def get_kth_row(self,board,k):
        return board[k]
    def get_kth_col(self,board,k):
        return [board[row][k] for row in range(9)]
    def get_cols(self,board):
        for col in range(10):
            yield [board[row][col] for row in range(9)]
    def get_rows(self,board):
        for i in range(9):
            yield board[i]
    def get_grid_at_row_col(self, board, row, col):
        row = row // 3*3
        col = col // 3*3
        return [
            board[r][c] for r, c in 
            product(range(row, row + 3), range(col, col + 3))
        ]
    def get_grids(self, board):
        for row in range(0, self.SHAPE, self.GRID):
            for col in range(0, self.SHAPE, self.GRID):
                grid = [
                    board[r][c] for r, c in 
                    product(range(row, row + self.GRID), range(col, col + self.GRID))
                ]
                yield grid
    def is_valid_state(self,board):
        for i in self.get_rows(board):
            if i!=self.d:
                return False
        for i in self.get_cols(board):
            if i!=self.d:
                return False
        for i in self.get_grids(board):
            if i!=self.d:
                return False
        return True
    def get_candidates(self,board,row,col):
        used=set()
        used.update(set(self.get_kth_row(board,row)))
        used.update(set(self.get_kth_col(board,col)))
        used.update(set(self.get_grid_at_row_col(board,row,col)))
        used-=set('.')
        return self.d-used
    def search(self,board):
        if self.is_valid_state(board):
            return True
        for ri,r in enumerate(board):
            for ci,e in enumerate(r):
                if e=='.':
                    for c in self.get_candidates(board,ri,ci):
                        board[ri][ci]=c
                        solved=self.search(board)
                        if solved:
                            return True
                        else:
                            board[ri][ci]='.'
                    return False
        return True
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.search(board)