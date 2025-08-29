class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        if (n + m)<3:
            return 0
        return (n*m)//2