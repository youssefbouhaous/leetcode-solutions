import decimal
class Solution:
    def fractionToDecimal(self, a: int, b: int) -> str:
        if a == 0:
            return '0'
        f = []
        if (a<0)^(b<0):
            f.append("-")
        a = abs(a)
        b = abs(b)
        f.append(str(a//b))
        r = a%b
        if r == 0:
            return "".join(f)
        f.append('.')
        mp= {}
        while r!= 0:
            if r in mp:
                f.insert(mp[r],'(')
                f.append(')')
                break
            mp[r] = len(f)
            r *= 10
            f.append(str(r//b))
            r %= b
        return "".join(f)