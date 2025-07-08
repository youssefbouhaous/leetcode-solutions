class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        ans=[]
        tmp=[]
        for i in s:
            if len(tmp)==k:
                ans.append("".join(tmp))
                tmp=[]
            tmp.append(i)
        tmp=tmp+[fill]*(k-len(tmp))
        ans.append("".join(tmp))
        return ans