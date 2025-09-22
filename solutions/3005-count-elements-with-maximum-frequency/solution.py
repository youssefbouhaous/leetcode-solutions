from collections import defaultdict
class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        mx = 0
        mp = defaultdict(int)
        cnt = 0
        for i in nums:
            mp[i] += 1
            mx = max(mx,mp[i])
        for j in nums:
           if mp[j] == mx:
            cnt+=1
        return cnt 
