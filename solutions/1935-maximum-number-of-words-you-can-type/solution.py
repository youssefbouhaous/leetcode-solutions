class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        l = text.split(" ")
        st = set(brokenLetters)
        ans = 0
        for i in l:
            f = True
            for j in st:
                if j in i:
                    f = False
                    break
            if f:
                ans+=1
        return ans