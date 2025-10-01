class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self. a = {}
        self.r = set()
        self.m = {}
        for s,m,p in entries:
            self.a[(m,s)] = p
            if m not in self.m:
                self.m[m] = []
            self.m[m].append((p,s))
        for i in self.m:
            self.m[i].sort()

    def search(self, movie: int) -> List[int]:
        ans = []
        for i in self.m.get(movie,[]):
            if (movie,i[1]) not in self.r:
                ans.append(i[1])
            if len(ans) == 5:
                return ans
        return ans

    def rent(self, shop: int, movie: int) -> None:
        self.r.add((movie,shop))

    def drop(self, shop: int, movie: int) -> None:
        self.r.discard((movie,shop))

    def report(self) -> List[List[int]]:
        ans = []
        for m,s in self.r:
            ans.append((self.a[(m,s)],s,m))
        ans.sort()
        return [[s,m] for p,s,m in ans[:5]]


# Your MovieRentingSystem object will be instantiated and called as such:
# obj = MovieRentingSystem(n, entries)
# param_1 = obj.search(movie)
# obj.rent(shop,movie)
# obj.drop(shop,movie)
# param_4 = obj.report()