n, k = map(int, input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))


count = 0
coins.reverse()
for coin in coins:
    count += k // coin
    k %= coin

print(count)
