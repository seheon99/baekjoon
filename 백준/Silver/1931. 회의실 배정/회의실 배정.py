n = int(input())
schedules = []
for _ in range(n):
    schedules.append(tuple(map(int, input().split())))

schedules.sort(key=lambda x: (x[1], x[0]))

now = 0
count = 0
for schedule in schedules:
    start, end = schedule
    if now <= start:
        count += 1
        now = end

print(count)
