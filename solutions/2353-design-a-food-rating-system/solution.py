import heapq
from collections import defaultdict

class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.n =len(foods)
        self.f = {}
        self.c = cuisines
        for i in range(self.n):
            self.f[foods[i]] = i
        self.mp = {}
        self.dele = defaultdict(bool)
        self.r = ratings
        for i in range(self.n):
            if cuisines[i] not in self.mp:
                self.mp[cuisines[i]] = []
            heapq.heappush(self.mp[cuisines[i]],(-ratings[i],foods[i]))
            
    def changeRating(self, food: str, newRating: int) -> None:
        self.dele[(-self.r[self.f[food]],food)]=True
        heapq.heappush(self.mp[self.c[self.f[food]]],(-newRating,food))
        self.dele[(-newRating,food)]=False
        self.r[self.f[food]] = newRating
        while  self.dele.get(self.mp[self.c[self.f[food]]][0]) == True:  
            heapq.heappop(self.mp[self.c[self.f[food]]])
    def highestRated(self, cuisine: str) -> str:
        return self.mp[cuisine][0][1]
