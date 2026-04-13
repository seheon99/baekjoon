import sys

input = sys.stdin.readline


n_gates, n = map(int, input().split())
t_gates = list(map(int, sys.stdin.readlines()))
t_max = max(t_gates)


def feasible(x):
    capacity = sum(map(lambda t: x // t, t_gates))
    return capacity >= n


lo, hi = 1, n * t_max
while lo <= hi:
    mid = (lo + hi) // 2
    if feasible(mid):
        hi = mid - 1
    else:
        lo = mid + 1

print(lo)
