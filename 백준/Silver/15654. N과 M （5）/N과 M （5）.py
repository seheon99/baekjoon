import itertools

n, m = map(int, input().split())
numbers = list(map(int, input().split()))
numbers.sort()

for comb in itertools.permutations(numbers, m):
    print(" ".join(map(str, comb)))
