class Solution(object):
    def removeDigit(self, number, digit):
        """
        :type number: str
        :type digit: str
        :rtype: str
        """
        f=0
        l=[]
        for i in range(len(number)):
            if(number[i]==digit):
                l.append(number[:i]+number[i+1:])
        return max(l)
        