class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        prev = self.countAndSay(n-1)
        l = [i for i in prev]
        h = []
        cnt = 1
        i = 0
        cur = l[0]
        while i < len(l)-1:
            if l[i] == l[i+1]:
                cnt += 1
            else:
                h.append(str(cnt))
                h.append(cur)
                cur = l[i+1]
                cnt = 1
            i += 1
        h.append(str(cnt))
        h.append(cur)
        return "".join(h)