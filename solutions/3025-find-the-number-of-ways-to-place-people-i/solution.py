class Solution:
    def numberOfPairs(self, p: List[List[int]]) -> int:
        p = sorted(p, key=lambda x: (x[0],-x[1]))
        ans = 0
        n = len(p)
        for i in range(n-1):
            j = i+1
            c1 = 0
            mx = -1
            while j<n:
                if p[i][1]>=p[j][1] and p[j][1]>mx:
                    ans+=1
                    mx=max(mx,p[j][1])
                j+=1
        return ans