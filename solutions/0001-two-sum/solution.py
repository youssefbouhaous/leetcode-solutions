class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d={}
        for i in nums:
            d[i]=[]
        for i in range(len(nums)):
            if d[nums[i]]==[]:
                d[nums[i]]=[i]
            else:
                d[nums[i]].append(i)
        for i in d.keys():
            if target-i in d and target!=i*2:
                return [d[target-i][0],d[i][0]]
            elif target-i in d and len(d[i])>1:
                return [d[i][0],d[i][1]]