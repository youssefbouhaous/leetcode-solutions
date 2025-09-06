class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        for i in range(61):
            if i>num1-i*num2:
                return -1
            elif i>=(num1-i*num2).bit_count():
                return i
        return -1