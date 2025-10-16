import heapq
class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        d = {}
        n = len(nums)
        for i in nums:
            m = i%value
            if m not in d:
                d[m] = 0
            d[m] += 1
        for i in range(n):
            x = i%value
            if x not in d or d[x] == 0:
                return i
            else:
                d[x] -= 1
        return n
