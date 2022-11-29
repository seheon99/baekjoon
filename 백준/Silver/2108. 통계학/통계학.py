import sys

lines = sys.stdin.readlines()
n = int(lines[0])
nums = []
for i in range(1, n + 1):
    nums.append(int(lines[i]))

nums.sort()
print(round(sum(nums) / len(nums)))
print(nums[len(nums) // 2])
count = [0] * 8001
for num in nums:
    count[num] += 1
max_count = max(count)
max_number = -10000
for i in range(-4000, 4001):
    if count[i] == max_count:
        if max_number == -10000:
            max_number = i
        else:
            max_number = i
            break
print(max_number)
print(nums[-1] - nums[0])
