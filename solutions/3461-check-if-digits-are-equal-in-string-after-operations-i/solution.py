class Solution:
    def hasSameDigits(self, s: str) -> bool:
        while len(s)>2:
            l = []
            n = len(s)
            for i in range(n-1):
                l.append(str((int(s[i])+int(s[i+1]))%10))
            s = "".join(l)
        return s[0] == s[1]