from functools import reduce

height, width, t_max = map(int, input().split())
dusts = [list(map(int, input().split())) for _ in range(height)]
purifier_top = []
purifier_bottom = []
dust_tot = 0

for y in range(height):
    for x in range(width):
        if dusts[y][x] == -1:
            if len(purifier_top) == 0:
                purifier_top = [x, y]
            else:
                purifier_bottom = [x, y]
        else:
            dust_tot += dusts[y][x]


def is_valid(x, y):
    return x >= 0 and x < width and y >= 0 and y < height and dusts[y][x] != -1


def diffuse_dusts():
    dusts_reference = [[dusts[y][x] for x in range(width)] for y in range(height)]
    for y in range(height):
        for x in range(width):
            if [x, y] == purifier_top or [x, y] == purifier_bottom:
                continue

            dx = [1, -1, 0, 0]
            dy = [0, 0, 1, -1]
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if is_valid(nx, ny):
                    dusts[ny][nx] += dusts_reference[y][x] // 5
                    dusts[y][x] -= dusts_reference[y][x] // 5


def circulate_oneside(purifier: list[int], dx: list[int], dy: list[int]) -> int:
    px, py = purifier
    cx, cy = px, py
    dust = 0
    for i in range(4):
        while True:
            nx, ny = cx + dx[i], cy + dy[i]
            if not is_valid(nx, ny):
                break
            cx, cy = nx, ny
            dust, dusts[cy][cx] = dusts[cy][cx], dust
    return dust


def circulate_top_air() -> int:
    dx = [1, 0, -1, 0]
    dy = [0, -1, 0, 1]
    return circulate_oneside(purifier_top, dx, dy)


def circulate_bottom_air() -> int:
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    return circulate_oneside(purifier_bottom, dx, dy)


def circulate_air() -> int:
    return circulate_top_air() + circulate_bottom_air()


for _ in range(t_max):
    diffuse_dusts()
    dust_tot -= circulate_air()

print(dust_tot)
