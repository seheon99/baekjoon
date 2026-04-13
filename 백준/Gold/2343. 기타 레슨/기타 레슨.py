import sys

input = sys.stdin.readline


n_lectures, n_bluelays = map(int, input().split())
min_lectures = list(map(int, input().split()))


def feasible(size):
    n = 1
    left = size
    for x in min_lectures:
        left -= x
        if left < 0:
            n += 1
            left = size - x
    return n <= n_bluelays


lo, hi = max(min_lectures), sum(min_lectures)
while lo <= hi:
    mid = (lo + hi) // 2
    if feasible(mid):
        hi = mid - 1
    else:
        lo = mid + 1

print(lo)
