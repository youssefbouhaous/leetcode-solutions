class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        l=[]
        n=len(word1)
        m=len(word2)
        i=0
        while i<max(n,m):
            if i<n:
                l.append(word1[i])
            if i<m:
                l.append(word2[i])
            i+=1
        return ''.join(l)