from itertools import combinations

houses: list[tuple[int, int]] = []
chickens: list[tuple[int, int]] = []

n, m = map(int, input().split())
for row in range(n):
    temp = list(map(int, input().split()))
    for col in range(n):
        if temp[col] == 1:
            houses.append((row + 1, col + 1))
        elif temp[col] == 2:
            chickens.append((row + 1, col + 1))

def chicken_distance(from_coord:tuple[int, int], chickens: list[tuple[int, int]]):
    return min(abs(cx - from_coord[0]) + abs(cy - from_coord[1]) for cx, cy in chickens)

def city_chicken_distance(chickens: list[tuple[int, int]]):
    return sum(chicken_distance(h, chickens) for h in houses)

print(min(city_chicken_distance(selected_chickens) for selected_chickens in combinations(chickens, m)))
