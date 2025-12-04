class Solution:
    def checkDivisibility(self, n: int) -> bool:
        p = 1
        s = 0
        nn = n
        while n>0:
            p*=n%10
            s+=n%10
            n //=10
        if p +s ==0 :
            return False
        return nn%(p+s) == 0