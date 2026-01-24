class Solution:
    def checkStraightLine(self, c: List[List[int]]) -> bool:
        c.sort()
        # y = a*x+b
        if len(c) == 2:
            return True
        '''
        y1 = ax1+b
        y2 = ax2+b 
        y1-y2 = a(x1-x2) => a = (y1-y2)/(x1-x2) if x1!=x2
        if x1 == x2 all other x's should be equal
        if y1 == y2 all other y's should be equal
        '''

        x1,y1= c[0]
        x2,y2=c[1]
        if x1 == x2:
            return all(c[i][0] == c[i+1][0] for i in range(len(c)-1))
        if y1 == y2:
            return all(c[i][1] == c[i+1][1] for i in range(len(c)-1))
        a = (y1-y2)/(x1-x2)
        b = y1-x1*a
        return all( c[i][1] == c[i][0]*a+b for i in range(len(c)))
