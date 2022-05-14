import sys

input = sys.stdin.readline
note = [0 for _ in range(100000)]
note_length = 0
number_of_costs = int(input())
for _ in range(number_of_costs):
    cost = int(input())
    if cost == 0:
        note_length -= 1
    else:
        note[note_length] = cost
        note_length += 1

sum_of_costs = 0
for i in range(note_length):
    sum_of_costs += note[i]

print(sum_of_costs)
