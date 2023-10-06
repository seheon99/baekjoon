import itertools

n, m = map(int, input().split())
numbers = map(str, sorted(list(map(int, input().split()))))

printed = []
for p in itertools.combinations(numbers, m):
    answer = " ".join(p)
    if answer not in printed:
        print(answer)
        printed.append(answer)
