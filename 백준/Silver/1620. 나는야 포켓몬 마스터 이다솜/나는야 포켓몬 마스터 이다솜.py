from sys import stdin

input = lambda: stdin.readline().rstrip()

n, m = map(int, input().split())

search = [None for _ in range(n)]
book = {}
for i in range(n):
    name = input()
    search[i] = name
    book[name] = i + 1

for _ in range(m):
    quiz = input()
    try:
        print(search[int(quiz) - 1])
    except:
        print(book[quiz])
