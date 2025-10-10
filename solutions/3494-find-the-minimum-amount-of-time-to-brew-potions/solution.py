class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        m = len(mana)
        n = len(skill)
        pre = [0]*n
        for j in mana:
            ans = 0
            for i in range(n):
                ans = max(ans,pre[i]) + skill[i]*j
            pre[n-1] = ans
            for i in range(n-2,-1,-1):
                pre[i] = pre[i+1] - skill[i+1]*j
        return pre[n-1]