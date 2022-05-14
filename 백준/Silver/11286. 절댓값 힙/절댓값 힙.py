import sys
import heapq

input = sys.stdin.readline
heap = []

number_of_x = int(input())
for _ in range(number_of_x):
    x = int(input())
    if x == 0:
        print(heapq.heappop(heap)[1] if heap else 0)
    else:
        heapq.heappush(heap, (abs(x), x))
