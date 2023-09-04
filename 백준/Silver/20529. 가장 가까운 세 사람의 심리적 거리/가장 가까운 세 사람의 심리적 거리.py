import sys
import collections

input = lambda: sys.stdin.readline().rstrip()


def _distance(a, b):
    return sum([1 for i in range(4) if a[i] != b[i]])


def distance(a, b, c):
    return _distance(a, b) + _distance(b, c) + _distance(c, a)


t = int(input())
for _ in range(t):
    _ = int(input())
    mbtis = input().split()
    counter = collections.Counter(mbtis)
    mbtis = [mbti for mbti, count in counter.items() for _ in range(min(count, 3))]
    print(
        min(
            [
                distance(mbtis[i], mbtis[j], mbtis[k])
                for i in range(len(mbtis))
                for j in range(i + 1, len(mbtis))
                for k in range(j + 1, len(mbtis))
            ]
        ),
    )
