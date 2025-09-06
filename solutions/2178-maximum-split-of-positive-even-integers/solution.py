class Solution:
    def maximumEvenSplit(self, f: int) -> List[int]:
        if f%2==1:
            return []
        o = 2
        ans = []
        s = 0
        while f>=0:
            if o>f:
                ans[-1]=ans[-1]+f-s
                break
            else:
                ans.append(o)
                f-=o
                o+=2
        return ans

              
        