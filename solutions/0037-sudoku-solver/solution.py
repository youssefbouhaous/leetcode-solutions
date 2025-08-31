from typing import List

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        l = [set() for _ in range(9)]
        c = [set() for _ in range(9)]
        b = [set() for _ in range(9)]
        digits = [str(x) for x in range(1, 10)]

        for i in range(9):
            for j in range(9):
                val = board[i][j]
                if val != '.':
                    l[i].add(val)
                    c[j].add(val)
                    k = (i // 3) * 3 + (j // 3)
                    b[k].add(val)

        def backtrack():
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        k = (i // 3) * 3 + (j // 3)
                        for x in digits:
                            if x not in l[i] and x not in c[j] and x not in b[k]:
                                board[i][j] = x
                                l[i].add(x)
                                c[j].add(x)
                                b[k].add(x)

                                if backtrack():
                                    return True

                                board[i][j] = '.'
                                l[i].discard(x)
                                c[j].discard(x)
                                b[k].discard(x)
                        return False
            return True

        backtrack()
