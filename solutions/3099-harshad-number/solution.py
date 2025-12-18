class Solution:
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        n = sum([int(i) for i in str(x)])
        if x%n == 0 :
            return n
        return -1