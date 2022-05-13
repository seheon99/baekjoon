import sys
import heapq

input = sys.stdin.readline

number_of_numbers = int(input())
heap = []
for _ in range(number_of_numbers):
    number = int(input())
    if number == 0:
        if heap:
            print(heapq.heappop(heap)[1])
        else:
            print(0)
    else:
        heapq.heappush(heap, [-number, number])
