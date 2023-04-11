from sys import stdin
input = stdin.readline
n, m, b = map(int, input().split())
land = [0 for i in range(257)]
for _ in range(n):
    for h in map(int, input().split()):
        land[h] += 1

block_left = b
time = 0
idx_min = 0
idx_max = 256
land_tot = n * m
while land[idx_min] == 0:
    idx_min += 1
while land[idx_max] == 0:
    idx_max -= 1

while idx_min < idx_max:
    if land[idx_min] <= land_tot * 2 / 3 and block_left >= land[idx_min]:
        time += land[idx_min]
        land[idx_min + 1] += land[idx_min]
        block_left -= land[idx_min]
        land[idx_min] = 0
        idx_min += 1
    else:
        time += 2 * land[idx_max]
        land[idx_max - 1] += land[idx_max]
        block_left += land[idx_max]
        land[idx_max] = 0
        idx_max -= 1
print(time, idx_min)

# f\left(x,\ k\right)\ =\ \left\{x<k:\ 2k-2x,\ x\ge k:\ x-k\right\}