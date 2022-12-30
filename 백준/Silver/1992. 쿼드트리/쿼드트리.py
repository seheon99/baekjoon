n = int(input())
dots = []
for _ in range(n):
    dots.append(input())


def check(x: int, y: int, size: int) -> bool:
    crit = dots[y][x]
    for i in range(size):
        for j in range(size):
            if dots[y + i][x + j] != crit:
                return False
    return True


def compress(x: int, y: int, size: int) -> None:
    if check(x, y, size):
        print(dots[y][x], end="")
    else:
        print("(", end="")
        sub_coord = [
            (x, y),
            (x + size // 2, y),
            (x, y + size // 2),
            (x + size // 2, y + size // 2),
        ]
        for sub_x, sub_y in sub_coord:
            compress(sub_x, sub_y, size // 2)
        print(")", end="")


compress(0, 0, n)
print()
