import sys


n, k = map(int, sys.stdin.readlines())


def calc(x):
    count = 0
    for i in range(1, n + 1):
        count += min(x // i, n)
    return count


lo, hi = 1, n**2
while lo <= hi:
    mid = (lo + hi) // 2
    if calc(mid) < k:
        lo = mid + 1
    else:
        hi = mid - 1

print(lo)
