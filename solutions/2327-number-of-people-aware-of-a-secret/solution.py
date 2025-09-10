class Solution:
    def peopleAwareOfSecret(self, n: int, d: int, f: int) -> int:
        @cache
        def g(i):
            if i>n:
                return 0
            c = 0
            for j in range(d+i,f+i):
                if j<=n:
                    c += g(j)
            if i>n-f:
                return (1+c)%(10**9+7)
            else:
                return c%(10**9+7)
        return g(1)