class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        d={}
        for i in nums:
            d[i]=True
        ans=-1
        for i in nums:
            if d.get(i,False)==True:
                tmp=0
                p=i
                while d.get(p)!=None:
                    tmp+=1
                    p*=p
                if tmp>1:
                    ans=max(ans,tmp)
        return ans
        