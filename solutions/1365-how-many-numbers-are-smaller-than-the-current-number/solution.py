class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        s = sorted(nums)
        ans = []
        n = len(nums)
        for i in range(n):
            c = 0
            l = 0
            r = n-1
            while l<=r:
                m = (l+r)//2
                if s[m]<nums[i]:
                    c = max(c,m+1)
                    l = m+1
                else:
                    r = m -1
            ans.append(c)
        return ans
