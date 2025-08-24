class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        #my idea here is to compresse the array y grouping the ones
        #then i can check for each 0 what is the best result if i delete it
        l = []
        o = 0
        ans = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                l.append(o)
                o = 0
                l.append(0)
            elif i == len(nums) - 1:
                l.append(o+1)
            else:
                o += 1
        # the naive anwser is the max(max,0)
        ans = max(max(l)-1,0)
        for i in range(1,len(l)-1):
            if l[i] == 0:
                ans=max(ans,l[i-1]+l[i+1])
        return ans