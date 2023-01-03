from sys import stdin

input = lambda: stdin.readline().rstrip()

n, m = map(int, input().split())
tomato = []

for k in range(m):
    tomato.append(list(map(int, input().split())))

from queue import Queue

work_q = Queue()
for y in range(m):
    for x in range(n):
        if tomato[y][x] == 1:
            work_q.put((x, y))

while not work_q.empty():
    x, y = work_q.get()
    if x - 1 >= 0 and tomato[y][x - 1] == 0:
        tomato[y][x - 1] = tomato[y][x] + 1
        work_q.put((x - 1, y))
    if x + 1 < n and tomato[y][x + 1] == 0:
        tomato[y][x + 1] = tomato[y][x] + 1
        work_q.put((x + 1, y))
    if y - 1 >= 0 and tomato[y - 1][x] == 0:
        tomato[y - 1][x] = tomato[y][x] + 1
        work_q.put((x, y - 1))
    if y + 1 < m and tomato[y + 1][x] == 0:
        tomato[y + 1][x] = tomato[y][x] + 1
        work_q.put((x, y + 1))

if True in map(lambda x: 0 in x, tomato):
    print(-1)
else:
    print(max(map(max, tomato)) - 1)
