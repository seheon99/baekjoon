expression = input()

operators = ["+", "-", "*", "/", "(", ")"]
stack = []
for ch in expression:
    if ch not in operators:
        print(ch, end="")

    if ch == ")":
        while len(stack) > 0 and stack[-1] != "(":
            print(stack.pop(), end="")
        stack.pop()
    elif ch == "*" or ch == "/":
        while len(stack) > 0 and (stack[-1] == "*" or stack[-1] == "/"):
            print(stack.pop(), end="")
        stack.append(ch)
    elif ch == "+" or ch == "-":
        while len(stack) > 0 and stack[-1] != "(":
            print(stack.pop(), end="")
        stack.append(ch)
    elif ch == "(":
        stack.append(ch)
for ch in reversed(stack):
    if ch != "(" and ch != ")":
        print(ch, end="")
