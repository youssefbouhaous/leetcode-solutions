from math import gcd, lcm
class Solution:
    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 2
        for i in range(n):
            p = 1
            g = nums[i]
            l = nums[i]
            for j in range(i,n):
                p*=nums[j]
                g = gcd(g,nums[j])
                l = lcm(l,nums[j])
                if j-i+1 > ans and p == l*g:
                    ans = j - i +1
        return ans