class Solution:
    def maxBottlesDrunk(self, n: int, x: int) -> int:
        ans = 0
        e = 0
        while n>0:
            ans += n
            e += n
            n = 0
            if x<=e:
                n += 1
                e -= x
            else:
                break
            x += 1
        return ans+n