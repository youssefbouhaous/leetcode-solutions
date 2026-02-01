class Solution:
    def nextGreatestLetter(self, l: List[str], t: str) -> str:
        b = l[0]
        l.sort()
        for i in l:
            if i > t:
                return i
        return b