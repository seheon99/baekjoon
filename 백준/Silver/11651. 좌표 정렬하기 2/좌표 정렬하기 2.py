n = int(input())
coords = []
for i in range(1, n + 1):
    coords.append(list(map(int, input().split())))
coords.sort(key=lambda x: (x[1], x[0]))
for x, y in coords:
    print(x, y)
