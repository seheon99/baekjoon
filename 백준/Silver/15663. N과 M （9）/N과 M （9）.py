import itertools

n, m = map(int, input().split())
numbers = list(map(int, input().split()))
permutations = list(set(itertools.permutations(numbers, m)))
permutations.sort()

for x in permutations:
    print(" ".join(map(str, x)))
