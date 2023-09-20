def a_b_mod_c(a, b, c):
    if b == 1:
        return a % c

    a_b2_mod_c = a_b_mod_c(a, b // 2, c)
    if b % 2 == 0:
        return (a_b2_mod_c * a_b2_mod_c) % c
    else:
        return (a * a_b2_mod_c * a_b2_mod_c) % c


a, b, c = map(int, input().split())
print(a_b_mod_c(a, b, c))
