p = [0]*1005
p[0]=1
p[1]=1
ps = []
for i in range(1005):
    if p[i]==0:
        ps.append(i)
        for j in range(i*i,1005,i):
            p[j]=1
class Solution:
    def minSteps(self, n: int) -> int:
        ans = 0
        for i in ps:
            while n%i == 0:
                ans +=i
                n//=i
            if n==1:
                return ans