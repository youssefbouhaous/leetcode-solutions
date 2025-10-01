class Solution:
    def numWaterBottles(self, n: int, x: int) -> int:
        ans = n
        while n>=x:
            ans += n//x
            n = n//x+n%x
        return ans