class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        pre = [1]*n
        for i in range(1,n):
            if nums[i]>nums[i-1]:
                pre[i] = pre[i-1] + 1
        mx = max(pre)//2
        l = 1
        while l<n:
            if pre[l]<pre[l-1]:
                r = l
                while r+1<n and pre[r]<pre[r+1]:
                    r+=1
                r = min(r,n-1)
                if l != r :
                    mx = max(mx,min(pre[l-1],pre[r]))
                    l = r
                else:
                    l+=1
            else:
                l+=1
        return max(mx,1)
