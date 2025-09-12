class Solution:
    def doesAliceWin(self, s: str) -> bool:
        d = set(['a', 'e', 'i', 'o','u'])
        c = 0
        for i in s:
            if i in d:
                c+=1
        if c == 0:
            return False
        return True