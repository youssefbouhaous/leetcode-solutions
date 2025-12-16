class Solution:
    def minimumPushes(self, word: str) -> int:
        if len(word)<=8:
            return len(word)
        n = len(word)
        if n>24:
            return 8 + 16 + 24 + (n-24)*4
        elif n>16:
            return 8 + 16 + (n-16)*3
        else:
            return 8 + (n-8)*2