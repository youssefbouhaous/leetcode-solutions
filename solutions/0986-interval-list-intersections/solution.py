class Solution:
    def intervalIntersection(self, l: List[List[int]], h: List[List[int]]) -> List[List[int]]:
        ans=[]
        for i in l:
            a=i[0]
            b=i[1]
            for j in h:
                if b<j[0]:
                    print(b)
                    break
                elif (a>=j[0] and a<=j[1]) or (b>=j[0] and b<=j[1]) or (b>=j[0] and a<=j[0]) or (b>=j[1] and a<=j[1]):
                    ans.append([max(a,j[0]),min(b,j[1])])
                #print(i,j)
        return ans 