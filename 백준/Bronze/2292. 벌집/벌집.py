import math

n = int(input())

if n == 1:
    print(1)
elif n == 2:
    print(2)
else:
    print(math.floor(((n - 2) / 3 + 1 / 4) ** 0.5 - 1 / 2) + 2)
