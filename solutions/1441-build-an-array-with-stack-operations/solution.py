class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans = []
        j = 0
        for i in range(1,n+1):
            if j==len(target):
                break
            ans.append("Push")
            if  i == target[j]:
                j+=1
                continue
            else:
                ans.append("Pop")
            
        return ans