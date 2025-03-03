def binom_mod2(n, k):
    return 1 if (k & ~n) == 0 else 0
small_binom = [
    [1],           
    [1, 1],        
    [1, 2, 1],     
    [1, 3, 3, 1],  
    [1, 4, 1, 4, 1]
]

def binom_mod5(n, k):
    if k > n:
        return 0
    res = 1
    while n or k:
        n_i = n % 5
        k_i = k % 5
        if k_i > n_i:
            return 0
        res = (res * small_binom[n_i][k_i]) % 5
        n //= 5
        k //= 5
    return res

def f(n, k):
    m2 = binom_mod2(n, k)
    m5 = binom_mod5(n, k)
    for i in range(10):
        if i % 2 == m2 and i % 5 == m5:
            return i
    return 0

class Solution:
    def hasSameDigits(self, s: str) -> bool:
        a = 0
        b = 0
        n = len(s)
        for i in range(1, n - 2):
            a += int(s[i]) * f(n - 2, i)
        for i in range(2, n - 1):
            b += int(s[i]) * f(n - 2, i - 1)
        a += int(s[0]) + int(s[n - 2])
        b += int(s[1]) + int(s[n - 1])
        return a % 10 == b % 10
