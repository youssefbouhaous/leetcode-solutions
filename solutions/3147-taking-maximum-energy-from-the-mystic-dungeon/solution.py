class Solution:
    def maximumEnergy(self, e: List[int], k: int) -> int:
        n = len(e)
        for i in range(n-1,-1,-1):
            if i-k>=0:
                e[i-k] += e[i]
        return max(e)