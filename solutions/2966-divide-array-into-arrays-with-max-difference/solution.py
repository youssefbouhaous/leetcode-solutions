class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        h = []
        m = 0
        tmp=[]
        while m < len(nums):
            tmp.append(nums[m])
            m+=1
            if m%3==0:
                h.append(tmp)
                if tmp[-1] - tmp[0] > k:
                    return []
                tmp=[]
        return h
