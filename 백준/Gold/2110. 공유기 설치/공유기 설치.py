import sys

lines = sys.stdin.readlines()

n_houses, n_routers = map(int, lines[0].split())
coords = list(map(int, lines[1:]))
coords.sort()


def check(min_dist):
    count = 1
    last = coords[0]
    for i in range(1, n_houses):
        if coords[i] - last >= min_dist:
            count += 1
            last = coords[i]
    return count >= n_routers


lo, hi = 1, coords[-1] - coords[0]
while lo <= hi:
    mid = (lo + hi) // 2
    if check(mid):
        lo = mid + 1
    else:
        hi = mid - 1

print(hi)
