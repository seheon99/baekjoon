import itertools

n, m = map(int, input().split())
numbers = list(sorted(map(int, input().split())))
for nums in itertools.combinations_with_replacement(numbers, m):
    print(" ".join(str(n) for n in nums))
