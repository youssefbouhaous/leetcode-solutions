class Solution:
    def isRectangleOverlap(self, a: List[int], b: List[int]) -> bool:
        return not (
            a[2] <= b[0] or  
            a[0] >= b[2] or  
            a[3] <= b[1] or  
            a[1] >= b[3]    
        )