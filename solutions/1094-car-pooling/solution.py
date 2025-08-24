class Solution:
    def carPooling(self, trips: List[List[int]], c: int) -> bool:
        n = len(trips)
        pre = [0] * 1005
        for i in trips:
            pre[i[1]]+=i[0]
            pre[i[2]]-=i[0]
        if pre[0]>c:
            return False
        for i in range(1,len(pre)):
            pre[i] += pre[i-1]
            if pre[i]>c:
                return False
        return True