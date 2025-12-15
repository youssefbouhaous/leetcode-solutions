class Solution:
    def evalRPN(self, t: List[str]) -> int:
        def f(a,b,c):
            a = int(a)
            b = int(b)
            if c == "-":
                return str(a-b)
            if c == "+":
                return str(a+b)
            if c == "/":
                return str(int(a/b))
            if c == "*":
                return str(a*b)
        s = []
        for i in t:
            if i in {'-','+','/','*'}:
                b = s.pop()
                a = s.pop()
                s.append(f(a,b,i))
            else:
                s.append(i)
        return int(s[0])