l = int(input())
string = input()

sum = 0
for i, ch in enumerate(string):
    sum += (ord(ch) - ord("a") + 1) * (31**i)
print(sum % 1234567891)
