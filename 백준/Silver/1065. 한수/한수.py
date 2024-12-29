def isHan(n: int):
    numbers = list(map(int, str(n)))
    if len(numbers) == 1:
        return True

    diff = numbers[1] - numbers[0]
    return all(numbers[i] - numbers[i - 1] == diff for i in range(1, len(numbers)))


n = int(input())
print(len(list(filter(lambda x: x, (isHan(i) for i in range(1, n + 1))))))
