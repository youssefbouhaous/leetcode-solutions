class Solution:
    def maximumEvenSplit(self, f: int) -> List[int]:
        if f%2==1:
            return []
        oo = f
        ans = set()
        o = 2
        while f>0:
            if f-o>=0 and (o not in ans) and (f-o not in ans):
                ans.add(o)
                f-=o
                o+=2
            else:
                ans.add(f)
                break
        if f!=0 and oo != sum(ans):
            if f in ans:
                for i in ans:
                    if (i+f not in ans) :
                        ans.remove(i)
                        ans.add(i+f)
                        break
            else:
                ans.add(f)
        return list(ans)

              
        