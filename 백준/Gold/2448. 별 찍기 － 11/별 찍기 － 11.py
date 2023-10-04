def draw_stars(x, y, h):
    if h == 3:
        draw_star(x, y)
    else:
        half_h = h // 2
        draw_stars(x + half_h, y, half_h)
        draw_stars(x, y + half_h, half_h)
        draw_stars(x + h, y + half_h, half_h)


def draw_star(x, y):
    TRIANGLE = [
        "  *  ",
        " * * ",
        "*****",
    ]
    for yi in range(3):
        for xi in range(5):
            lines[y + yi][x + xi] = TRIANGLE[yi][xi]


n = int(input())
lines = [[" " for _ in range(2 * n - 1)] for _ in range(n)]

draw_stars(0, 0, n)
for line in lines:
    print("".join(line))
