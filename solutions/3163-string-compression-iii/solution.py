class Solution:
    def compressedString(self, word: str) -> str:
        c,o=word[0],1
        ans=""
        for i in range(1,len(word)):
            if c!=word[i]:
                ans+=str(o)+c
                c,o=word[i],1
            elif o==9:
                ans+=str(o)+c
                o=1
            else:
                o+=1
        ans+=str(o)+c
        return ans