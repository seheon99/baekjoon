from math import ceil

n = int(input())
sizes = map(int, input().split())
t, p = map(int, input().split())

print(sum(map(lambda a: ceil(a / t), sizes)))
print(n // p, n % p)