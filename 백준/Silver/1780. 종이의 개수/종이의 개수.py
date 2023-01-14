from sys import stdin

input = lambda: stdin.readline().rstrip()

n = int(input())
map = [list(map(int, input().split())) for _ in range(n)]


def check(coord: tuple[int, int], size: int) -> bool:
    x, y = coord
    for xi in range(x, x + size):
        for yi in range(y, y + size):
            if map[yi][xi] != map[y][x]:
                return False
    return True


def count(coord: tuple[int, int], size: int) -> tuple[int, int, int]:
    x, y = coord
    nxy = map[y][x]
    if check(coord, size):
        return (1, 0, 0) if nxy == -1 else (0, 1, 0) if nxy == 0 else (0, 0, 1)

    nn, nz, np = 0, 0, 0
    gap = size // 3
    for yi in [y, y + gap, y + gap * 2]:
        for xi in [x, x + gap, x + gap * 2]:
            nni, nzi, npi = count((xi, yi), gap)
            nn, nz, np = nn + nni, nz + nzi, np + npi

    return nn, nz, np


nn, nz, np = count((0, 0), n)
print(nn)
print(nz)
print(np)
