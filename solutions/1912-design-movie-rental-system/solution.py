import heapq
class MovieRentingSystem:
    
    def __init__(self, n: int, entries: List[List[int]]):
        self.rented = set()
        self.added = set()
        self.unrented = {}
        self.movies = []
        self.p = {}
        for s,m,p in entries:
            if m not in self.unrented:
                self.unrented[m] = []
            heapq.heappush(self.unrented[m],(p,s))
            self.p[(m,s)] = p

    def search(self, movie: int) -> List[int]:
        if movie not in self.unrented:
            return []
        l = self.unrented[movie]
        ans = []
        k = []
        while len(l)>0 and len(ans)<5:
            p,s = heapq.heappop(l)
            k.append((p,s))
            if (movie,s) not in self.rented:
                ans.append(s)
        while len(k)>0:
            heapq.heappush(self.unrented[movie],k[-1])
            k.pop()
        return ans

    def rent(self, shop: int, movie: int) -> None:
        self.rented.add((movie,shop))
        if not (movie,shop) in self.added:
            self.added.add((movie,shop))
            heapq.heappush(self.movies,(self.p[(movie,shop)],shop,movie))

    def drop(self, shop: int, movie: int) -> None:
        self.rented.discard((movie, shop))

    def report(self) -> List[List[int]]:
        ans = []
        k = []
        while len(ans)<5 and len(self.movies)>0:
            p,s,m = heapq.heappop(self.movies)
            if (m,s) in self.rented:
                ans.append([s,m])
            k.append((p,s,m))
        while len(k)>0:
            heapq.heappush(self.movies,k.pop())
        return ans

# Your MovieRentingSystem object will be instantiated and called as such:
# obj = MovieRentingSystem(n, entries)
# param_1 = obj.search(movie)
# obj.rent(shop,movie)
# obj.drop(shop,movie)
# param_4 = obj.report()