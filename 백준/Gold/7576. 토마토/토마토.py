width, height = map(int, input().split())

tomatos = []
for _ in range(height):
    tomatos.append(list(map(int, input().split())))

queue = []

for y in range(height):
    for x in range(width):
        if tomatos[y][x] == 1:
            queue.append((x, y, 0))

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
result = 0
for x, y, count in queue:
    result = count
    for i in range(4):
        xi = x + dx[i]
        yi = y + dy[i]
        if yi >= 0 and yi < height and xi >= 0 and xi < width and tomatos[yi][xi] == 0:
            tomatos[yi][xi] = 1
            queue.append((xi, yi, count + 1))

for line in tomatos:
    if 0 in line:
        result = -1
        break

print(result)
