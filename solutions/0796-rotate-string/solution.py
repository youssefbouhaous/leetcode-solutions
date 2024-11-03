class Solution:
    def rotateString(self, s: str, g: str) -> bool:
        n=len(s)
        m=len(g)
        if n!=m:
            return False
        for i in range(n):
            if s==g[i:]+g[:i]:
                return True
        return False