class Solution:
    def removeCoveredIntervals(self, l: List[List[int]]) -> int:
        l.sort(key=lambda x: (x[0], -x[1]))
        c=0
        if len(l)==1:
            return 1
        if l[0][0]==l[1][0] and l[0][1]==l[1][1]:
            c+=1
        m=l[0][1]
        for i in range(1,len(l)):
            if m>=l[i][1]:
                c+=1
            m=max(m,l[i][1])
        return len(l)-c