t = int(input())

for _ in range(t):
    command = input()
    n = int(input())
    nums = list(map(lambda x: x.strip("[]"), input().split(",")))

    head = 0
    tail = n
    rev = False
    ok = True

    for f in command:
        if f == "R":
            rev = ~rev
        elif f == "D":
            if head == tail:
                print("error")
                ok = False
                break
            elif rev:
                tail -= 1
            else:
                head += 1

    if ok:
        print("[", end="")
        if rev:
            print(",".join(reversed(nums[head:tail])), end="")
        else:
            print(",".join(nums[head:tail]), end="")
        print("]")
