import sys

input = lambda: sys.stdin.readline().rstrip()

scores: tuple[list[int], list[int]]


def get_score(
    x: int,
    prev_y: int,
):
    cache = get_score.cache
    if cache[x][prev_y] == None:
        cache[x][prev_y] = max(
            scores[0][x] + get_score(x + 1, 0) if prev_y != 0 else 0,
            scores[1][x] + get_score(x + 1, 1) if prev_y != 1 else 0,
            0 + get_score(x + 1, 2),
        )
    return cache[x][prev_y]


t = int(input())
for _ in range(t):
    n = int(input())
    scores = (
        list(map(int, input().split())),
        list(map(int, input().split())),
    )
    cache = [[None, None, None] for _ in range(n + 1)]
    cache[n] = [0, 0, 0]
    for x in range(n - 1, -1, -1):
        cache[x][0] = scores[0][x] + max(cache[x + 1][1], cache[x + 1][2])
        cache[x][1] = scores[1][x] + max(cache[x + 1][0], cache[x + 1][2])
        cache[x][2] = 0 + max(cache[x + 1][0], cache[x + 1][1])
    print(max(cache[0]))
