class Solution:
    def isItPossible(self, word1: str, word2: str) -> bool:
        a = {}
        b = {}
        for i in word1:
            if i not in a:
                a[i] = 1
                continue
            a[i] = a[i] + 1
        for i in word2:
            if i not in b:
                b[i] = 1
                continue
            b[i] = b[i] + 1
        al = [chr(i) for i in range(ord('a'),ord('z')+1)]
        for i in al:
            for j in al:
                if not(i in a and j in b):
                    continue
                o = a[i]
                u = b[j]
                if o == 1:
                    a.pop(i)
                else:
                    a[i]-=1
                if u == 1:
                    b.pop(j)
                else:
                    b[j]-=1
                n = len(a)
                m = len(b)
                if j not in a:
                    n+=1
                if i not in b:
                    m+=1
                if n == m:
                    return True
                a[i]=o
                b[j]=u
        return False