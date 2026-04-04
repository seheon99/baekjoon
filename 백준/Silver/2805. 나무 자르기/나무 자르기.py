from sys import stdin

input = stdin.readline

n, m = map(int, input().split())
trees = list(map(int, input().split()))

lo, hi = 0, max(trees)
while lo <= hi:
    mid = (lo + hi) // 2
    if sum(max(0, x - mid) for x in trees) >= m:
        lo = mid + 1
    else:
        hi = mid - 1

print(hi)
