class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        s = set([i for i in range(1,len(nums)+1)])
        ans = []
        for i in nums:
            if i in s:
                s.discard(i)
        return list(s)