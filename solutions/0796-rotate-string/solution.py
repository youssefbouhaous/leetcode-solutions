class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        n=len(s)
        m=len(goal)
        if n!=m:
            return False
        for i in range(n):
            if s[1:]+s[0]==goal:
                return True
            s=s[1:]+s[0]
        return False