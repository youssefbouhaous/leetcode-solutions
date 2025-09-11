class Solution:
    def minimumTeachings(self, n: int, l: List[List[int]], f: List[List[int]]) -> int:
        no = set()
        for a,b in f:
            mp = {}
            can = False
            for i in l[a-1]:
                mp[i] = 1
            for i in l[b-1]:
                if i in mp:
                    can = True
                    break
            if not can :
                no.add(a-1)
                no.add(b-1)
        maxc=0
        cnt = [0]*(n+1)
        for i in no:
            for j in l[i]:
                cnt[j] += 1
                maxc = max(maxc,cnt[j])
        return len(no) - maxc