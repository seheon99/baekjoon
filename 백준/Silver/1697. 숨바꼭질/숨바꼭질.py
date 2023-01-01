from queue import Queue

n, k = map(int, input().split())

road = [None for _ in range(100001)]
road[n] = 0

work_q = Queue()
work_q.put(n)
while not work_q.empty():
    n = work_q.get()
    if n == k:
        print(road[n])
        exit(0)
    if n > 0 and road[n - 1] is None:
        road[n - 1] = road[n] + 1
        work_q.put(n - 1)
    if n < 100000 and road[n + 1] is None:
        road[n + 1] = road[n] + 1
        work_q.put(n + 1)
    if n * 2 <= 100000 and road[n * 2] is None:
        road[n * 2] = road[n] + 1
        work_q.put(n * 2)
