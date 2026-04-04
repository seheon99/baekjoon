import sys

input = sys.stdin.readline

k, n = map(int, input().split())
lines = [int(input()) for _ in range(k)]

lo, hi = 1, max(lines)
while lo <= hi:
    mid = (lo + hi) // 2
    if sum(x // mid for x in lines) >= n:
        lo = mid + 1
    else:
        hi = mid - 1

print(hi)
