class Solution:
    def isCircularSentence(self, l: str) -> bool:
        l=l.split()
        if len(l)==2:
            if l[0][-1]!=l[1][0]:
                return False
        if l[0][0]!=l[-1][-1]:
            return False
        for i in range(1,len(l)-1):
            if l[i][0]!=l[i-1][-1] or l[i][-1]!=l[i+1][0]:
                return False
        return True