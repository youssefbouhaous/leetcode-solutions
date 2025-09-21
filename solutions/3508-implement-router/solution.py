from collections import defaultdict
from collections import deque

class Router:

    def __init__(self, memoryLimit: int):
        self.n = memoryLimit
        self.p = deque()
        self.d = defaultdict(bool)
        self.ps = defaultdict(deque)
    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        x = (source,destination,timestamp)
        if self.d[x]:
            return False
        if len(self.p)<self.n:
            self.p.append(x)
            self.d[x] = True
            self.ps[x[1]].append(x)
            return True
        else:
            y = self.p.popleft()
            self.d[y] = False
            if len(self.ps[y])!=0:
                self.ps[y[1]].popleft()
            self.p.append(x)
            self.d[x] = True
            self.ps[x[1]].append(x)
            return True
        return False

    def forwardPacket(self) -> List[int]:
        if len(self.p)==0:
            return []
        x = self.p.popleft()
        self.d[x] = False
        if len(self.ps[x[1]])!=0:
            self.ps[x[1]].popleft()
        return list(x)

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        dc = self.ps[destination]
        if len(dc) == 0:
            return 0
        l = 0
        r = len(dc)-1
        li = -1
        while l<=r:
            m = (l+r)//2
            if self.d[dc[m]] == False or dc[m][2]<startTime:
                l = m+1
                continue
            else:
                li = m
                r = m-1
        if li >= len(dc) or li == -1:
            return 0
        if self.d[dc[li]]== False:
            return 0
        l = 0
        r = len(dc)-1
        ri = -1
        while l<=r:
            m = (l+r)//2
            if dc[m] == endTime:
                ri = m
                break
            if dc[m][2]>endTime:
                r = m-1
            else:
                l = m+1
                ri = m
        if ri<li:
            return 0
        if self.d[dc[ri]] == False:
            return 0
        return ri-li+1


# Your Router object will be instantiated and called as such:
# obj = Router(memoryLimit)
# param_1 = obj.addPacket(source,destination,timestamp)
# param_2 = obj.forwardPacket()
# param_3 = obj.getCount(destination,startTime,endTime)