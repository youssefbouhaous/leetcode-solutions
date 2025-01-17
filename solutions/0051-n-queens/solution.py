class Solution:
    def is_valid_state(self,state,n):
        return len(state)==n


    def get_candidate(self,state,n):
        if not state:
            return  range(n)
        #check for others
        position=len(state)
        candidates=set(range(n))
        for row , col in enumerate(state):
            candidates.discard(col)
            dist=position-row
            candidates.discard(col+dist)
            candidates.discard(col-dist)
        return candidates

    def search(self,state,solutions,n):
        if self.is_valid_state(state,n):
            solutions.append(state.copy())
            return
        for candidate in self.get_candidate(state,n):
            state.append(candidate)
            self.search(state,solutions,n)
            state.pop()
    def solveNQueens(self, n: int) -> List[List[str]]:
        solutions = []
        state = []
        self.search(state,solutions,n)
        ans=[]
        for i in solutions:
            l=[]
            for j in i:
               s="."*j+"Q"+"."*(n-j-1)
               l.append(s)
            ans.append(l)
        return ans
        