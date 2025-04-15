class Solution:
    def longestPalindrome(self, s: str) -> str:
        n=len(s)
        ans=s[0]
        for i in range(n):
            l=i
            la=i
            ra=i
            r=i+1
            while( r<n and l>-1):
                if s[l]==s[r]:
                    la=l
                    ra=r
                    l-=1
                    r+=1
                else:
                    break
            if ra-la+1>len(ans):
                ans=s[la:ra+1]
            l=i
            la=i
            ra=i
            r=i
            while( r<n and l>-1):
                if s[l]==s[r]:
                    la=l
                    ra=r
                    l-=1
                    r+=1
                else:
                    break
            if ra-la+1>len(ans):
                ans=s[la:ra+1]
        return ans