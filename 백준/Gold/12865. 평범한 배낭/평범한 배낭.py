import sys


n_items, max_weight = map(int, sys.stdin.readline().split())
items = []
for _ in range(n_items):
    weight, value = map(int, sys.stdin.readline().split())
    items.append((weight, value))


cache = [[-1 for _ in range(max_weight + 1)] for _ in range(n_items)]


def dp(i, total_weight):
    if i == n_items:
        return 0
    if cache[i][total_weight] == -1:
        weight, value = items[i]
        if total_weight + weight > max_weight:
            cache[i][total_weight] = dp(i + 1, total_weight)
        else:
            cache[i][total_weight] = max(
                dp(i + 1, total_weight),
                value + dp(i + 1, total_weight + weight),
            )
    return cache[i][total_weight]


print(dp(0, 0))
