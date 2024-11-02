class Solution:
    def intervalIntersection(self, l: List[List[int]], h: List[List[int]]) -> List[List[int]]:
        ans=[]
        a,b=0,0
        n,m=len(l),len(h)
        while a<n and b<m:
            if l[a][0]>h[b][1]:
                b+=1
                continue
            if l[a][1]<h[b][0]:
                a+=1
                continue
            ans.append([max(l[a][0],h[b][0]),min(l[a][1],h[b][1])])
            if h[b][1]<=l[a][1]:
                b+=1
            else:
                a+=1
        return ans 