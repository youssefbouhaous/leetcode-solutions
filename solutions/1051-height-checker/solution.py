class Solution:
    def heightChecker(self, h: List[int]) -> int:
        
        l=h[:]
        l.sort()
        a=0
        for i in range(len(l)):
            if h[i]!=l[i]:
                a+=1
        return a