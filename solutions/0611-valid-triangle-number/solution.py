class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        ans = 0
        nums.sort()
        n = len(nums)
        for i in range(n-1,-1,-1):
            for j in range(i-1,-1,-1):
                l = 0
                r = j-1
                o = math.inf
                while l<=r:
                    m = (l+r)//2
                    if nums[m]> nums[i]-nums[j]:
                        r = m-1
                        o = min(m,o)
                    else:
                        l = m+1
                if o!= math.inf:
                    ans += j-o
        return ans