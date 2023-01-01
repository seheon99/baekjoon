from sys import stdin

lines = stdin.readlines()

n = int(lines[0])
schedules = []
for i in range(1, n + 1):
    schedules.append(tuple(map(int, lines[i].rstrip().split())))

schedules.sort(key=lambda x: (x[1], x[0]))

now = 0
count = 0
for schedule in schedules:
    start, end = schedule
    if now <= start:
        count += 1
        now = end

print(count)
