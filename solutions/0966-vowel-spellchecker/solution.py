from sortedcontainers import SortedSet
class Solution:
    def spellchecker(self, w: List[str], q: List[str]) -> List[str]:
        ans = []
        n = len(w)
        m = len(q)
        v = ('a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U')
        mapw = {}
        mapq = {}
        wset = set(w)
        vowelm = {}
        def vf(s):
            a = []
            for i in s:
                if i in v:
                    a.append("*")
                else:
                    a.append(i.lower())
            return "".join(a)
        for i in range(n):
            if w[i].lower() not in mapw:
                mapw[w[i].lower()] = w[i]
            a = []
            for u in w[i]:
                if u in v:
                    a.append("*")
                else:
                    a.append(u.lower())
            aw = "".join(a)
            if aw not in vowelm:
                vowelm[aw] = w[i]
        for i in q:
            if i in wset:
                ans.append(i)
            elif i.lower() in mapw:
                ans.append(mapw[i.lower()])
            else:
                e = vf(i)
                if e in vowelm:
                    ans.append(vowelm[e])
                else:
                    ans.append("")
        return ans