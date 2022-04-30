import sys
readline = sys.stdin.readline

number_of_inputs = int(readline())
stack = []
for _ in range(number_of_inputs):
    command = readline().split()
    if command[0] == 'push':
        stack.append(command[1])
    elif command[0] == 'pop':
        print(stack.pop() if len(stack) > 0 else '-1')
    elif command[0] == 'size':
        print(len(stack))
    elif command[0] == 'empty':
        print('1' if len(stack) == 0 else '0')
    elif command[0] == 'top':
        print(stack[-1] if len(stack) > 0 else '-1')