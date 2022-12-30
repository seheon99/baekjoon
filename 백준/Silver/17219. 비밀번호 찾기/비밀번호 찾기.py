from sys import stdin

input = stdin.readline

n, m = map(int, input().split())
passwd = {}

for _ in range(n):
    url, pw = input().split()
    passwd[url] = pw

for _ in range(m):
    url = input().rstrip()
    print(passwd[url])
