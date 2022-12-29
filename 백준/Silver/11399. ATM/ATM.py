_ = int(input())
p = list(map(int, input().split()))
p.sort()

k = len(p)
tot = 0
for t in p:
    tot += t * k
    k -= 1

print(tot)
