class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        a = abs(dividend)
        b = abs(divisor)
        t = 0
        while a>=b:
            q = 0
            while a >= (b<<(q+1)):
                q += 1
            a -= b<<q
            t += 1<<q
        if dividend*divisor<0:
            if -t<-2**31:
                return -2**31
            return -t
        if t>2**31-1:
            return 2**31-1
        return t