from collections import deque
from sys import stdin

readline = stdin.readline

number_of_commands = int(readline())
queue = deque()
answer = ''
for _ in range(number_of_commands):
    command = readline().split()
    if command[0] == 'push':
        queue.append(int(command[1]))
    elif command[0] == 'pop':
        print(queue.popleft() if queue else '-1')
    elif command[0] == 'size':
        print(len(queue))
    elif command[0] == 'empty':
        print('1' if not queue else '0')
    elif command[0] == 'front':
        print(queue[0] if queue else '-1')
    elif command[0] == 'back':
        print(queue[-1] if queue else '-1')
