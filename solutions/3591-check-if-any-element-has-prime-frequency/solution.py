from collections import defaultdict
class Solution:
    def checkPrimeFrequency(self, nums: List[int]) -> bool:
        n = 105
        isp = [1]*n
        isp[0] = 0
        isp[1] = 0
        for i in range(2,n):
            if isp[i] == 1:
                for j in range(i*i,n,i):
                    isp[j] = 0
        d = defaultdict(int)
        for i in nums:
            d[i] += 1
        for i in nums:
            if isp[d[i]] == 1:
                return True
        return False 

