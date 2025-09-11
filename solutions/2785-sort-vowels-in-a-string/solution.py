class Solution:
    def sortVowels(self, s: str) -> str:
        h = []
        v = []
        o = set(['a', 'e', 'i', 'o','u'])
        for i in s:
            if i.lower() in o:
                h.append("$")
                v.append(i)
            else:
                h.append(i)
        v.sort()
        v = v[::-1]
        for i in range(len(h)):
            if h[i] == "$":
                h[i] = v.pop(-1)
        return "".join(h)