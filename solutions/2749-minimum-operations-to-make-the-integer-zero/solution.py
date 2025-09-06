class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        for i in range(61):
            x = num1 - i*num2
            if i>x:
                return -1
            elif i>=x.bit_count():
                return i
        return -1