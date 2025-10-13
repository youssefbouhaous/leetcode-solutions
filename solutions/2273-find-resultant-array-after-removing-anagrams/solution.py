class Solution:
    def removeAnagrams(self, w: List[str]) -> List[str]:
        ans = [w[0]]
        n = len(w)
        for i in range(1,n):
            if sorted(w[i]) != sorted(ans[-1]):
                ans.append(w[i])
        return ans