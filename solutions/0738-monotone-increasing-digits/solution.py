class Solution:
    def monotoneIncreasingDigits(self, n: int) -> int:
        s = str(n)
        s = list(s)
        n = len(s)
        for i in range(n-1):
            if s[i]>s[i+1]:
                if i>0 and s[i]>s[i-1]:
                    s[i]=str(int(s[i])-1)
                    return int("".join(s[:i+1]) + "9"*(n-i-1))
                elif i==0:
                    return int(str(int(s[0])-1)+"9"*(n-1))
                else:
                    #here we should go to the first element == to s[i]
                    o = i
                    while o>-1 and s[o-1]==s[i]:
                        o-=1
                    s[o]=str(int(s[o])-1)
                    return int("".join(s[:o+1]) + "9"*(n-o-1))
        return int("".join(s))
