class Solution:
    def checkTwoChessboards(self, a: str, b: str) -> bool:
        return (ord(a[0])-ord('a')+int(a[1]))%2 == (ord(b[0])-ord('a')+int(b[1]))%2 