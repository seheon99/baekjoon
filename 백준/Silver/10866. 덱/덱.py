import sys

input = sys.stdin.readline

number_of_commands = int(input())

deque = [0 for _ in range(10000)]
deque_head = 0
deque_tail = 0

for _ in range(0, number_of_commands):
    command = input().split()
    if command[0] == 'push_front':
        deque[deque_head - 1] = command[1]
        deque_head -= 1
    elif command[0] == 'push_back':
        deque[deque_tail] = command[1]
        deque_tail += 1
    elif command[0] == 'pop_front':
        if deque_head < deque_tail:
            print(deque[deque_head])
            deque_head += 1
        else:
            print(-1)
    elif command[0] == 'pop_back':
        if deque_head < deque_tail:
            print(deque[deque_tail - 1])
            deque_tail -= 1
        else:
            print(-1)
    elif command[0] == 'size':
        print(deque_tail - deque_head)
    elif command[0] == 'empty':
        print(1 if deque_head == deque_tail else 0)
    elif command[0] == 'front':
        print(deque[deque_head] if deque_head < deque_tail else -1)
    elif command[0] == 'back':
        print(deque[deque_tail - 1] if deque_head < deque_tail else -1)
