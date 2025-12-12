from collections import defaultdict
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        d = defaultdict(int)
        t = 0
        n = len(nums)
        for i in nums:
            d[i] += 1
            if d[i] == 2:
                t = i
                break
        return [t,(n*(n+1)//2)-sum(nums)+t]
            
        
            