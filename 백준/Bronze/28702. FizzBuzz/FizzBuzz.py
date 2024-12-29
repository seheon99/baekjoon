a = input()
b = input()
c = input()

if a == 'FizzBuzz':
    print('Fizz')
elif a == 'Buzz':
    if b == 'Fizz':
        print(int(c) + 1)
    else:
        print(int(b) + 2)
elif a == 'Fizz':
    if c == 'Buzz':
        print('Fizz')
    elif int(c) % 5 == 4:
        print('FizzBuzz')
    else:
        print('Fizz')
else:
    if b == 'FizzBuzz' or b == 'Buzz' or (
        b == 'Fizz' and c == 'Buzz'
    ):
        print(int(a) + 3)
    elif b == 'Fizz':
        if int(c) % 5 == 4:
            print('Buzz')
        else:
            print(int(a) + 3)
    else:
        if int(a) % 5 == 2:
            print('Buzz')
        else:
            print(int(a) + 3)


# n     n       Fizz        n
# n     n       Fizz        Buzz
# n     n       FizzBuzz    n
# n     Fizz    n           n
# n     Fizz    n           Buzz
# n     Fizz    Buzz        n
# n     Buzz    Fizz        n
# n     FizzBuzz n          n
# Fizz  n       n           Fizz
# Fizz  n       n           FizzBuzz
# Fizz  n       Buzz        Fizz
# Fizz  Buzz    n           Fizz
# Buzz  n       Fizz        n
# Buzz  Fizz    n           n
# FizzBuzz n    n           Fizz