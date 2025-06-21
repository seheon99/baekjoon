n_numbers = int(input())
numbers = list(map(int, input().split()))

stack = []
answer = [-1 for i in range(n_numbers)]

for i in range(n_numbers):
    while stack and numbers[stack[-1]] < numbers[i]:
        answer[stack.pop()] = numbers[i]
    stack.append(i)

for i in answer:
    print(i, end=' ')