class Solution:
    def maxFreqSum(self, s: str) -> int:
        v = set(['a', 'e', 'i', 'o','u'])
        mp = {}
        vc = 0
        cc = 0
        for i in s:
            if i not in mp:
                mp[i] = 1
            else:
                mp[i] += 1
        for i in s:
            if i in v:
                vc = max(mp[i],vc)
            else:
                cc = max(cc,mp[i])
        return cc + vc