from collections import defaultdict
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        l=[]
        d = defaultdict(int)
        n=len(nums)
        for i in nums:
            d[i]+=1
        for i in d.keys():
            if d[i]>n//3:
                l.append(i)
        return l