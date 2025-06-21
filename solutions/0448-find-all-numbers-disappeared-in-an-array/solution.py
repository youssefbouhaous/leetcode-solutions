class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n=len(nums)
        l=set(nums)
        ans=[]
        for i in range(1,n+1):
            if not(i in l):
                ans.append(i)
        return ans