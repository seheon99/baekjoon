n, r, c = map(int, input().split())
result = 0

while n > 0:
    k = 2**n
    if r < k / 2:
        if c < k / 2:
            result += 4 ** (n - 1) * 0
        else:
            result += 4 ** (n - 1) * 1
    else:
        if c < k / 2:
            result += 4 ** (n - 1) * 2
        else:
            result += 4 ** (n - 1) * 3

    r %= k / 2
    c %= k / 2
    n -= 1

print(result)
