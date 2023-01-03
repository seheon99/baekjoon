from queue import Queue

n = int(input())
k = int(input())

computers = [False for _ in range(n + 1)]
connections: list[list[int]] = [[] for _ in range(n + 1)]

for _ in range(k):
    a, b = map(int, input().split())
    connections[a].append(b)
    connections[b].append(a)

work_q = Queue()
work_q.put(1)
while not work_q.empty():
    c = work_q.get()
    for t in connections[c]:
        if not computers[t]:
            computers[t] = True
            work_q.put(t)

print(computers.count(True) - 1)
