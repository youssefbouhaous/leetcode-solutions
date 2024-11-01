class Solution:
    def makeFancyString(self, s: str) -> str:
        n=len(s)
        if n<3:
            return s
        a=s[0]
        b=s[1]
        l=[a,b]
        i=2
        while i<n:
            if a==b and b==s[i]:
                i+=1
            else:
                l.append(s[i])
                a,b=b,s[i]
                i+=1
        return "".join(l)