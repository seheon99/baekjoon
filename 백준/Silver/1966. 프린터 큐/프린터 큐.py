t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    p = list(map(int, input().split()))
    count = 1
    while True:
        if max(p) != p[0]:
            p.append(p[0])
        elif m == 0:
            print(count)
            break
        else:
            count += 1
        p.pop(0)
        if m == 0:
            m = len(p) - 1
        else:
            m -= 1