class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        i=0
        j=0
        n=len(name)
        m=len(typed)
        if m<n:
            return False
        while i<n and j<m:
            if name[i]==typed[j]:
                c=name[i]
                cn=0
                ct=0
                while i<n and name[i]==c:
                    cn+=1
                    i+=1
                while j<m and typed[j]==c:
                    ct+=1
                    j+=1
                if cn>ct:
                    return False
            else:
                return False
        return i>=n and j>=m