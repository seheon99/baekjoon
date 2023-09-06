MOD = 1000000007

def matmul(A, B):
    return (
        [(A[0][0]*B[0][0] + A[0][1]*B[1][0]) % MOD, (A[0][0]*B[0][1] + A[0][1]*B[1][1]) % MOD],
        [(A[1][0]*B[0][0] + A[1][1]*B[1][0]) % MOD, (A[1][0]*B[0][1] + A[1][1]*B[1][1]) % MOD]
    )

def matpow(matrix, n):
    if n == 1:
        return matrix
    if n % 2:
        return matmul(matrix, matpow(matrix, n-1))
    half_pow = matpow(matrix, n // 2)
    return matmul(half_pow, half_pow)

def fibo(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    base_matrix = [[1, 1], [1, 0]]
    result_matrix = matpow(base_matrix, n-1)
    return result_matrix[0][0]

n = int(input())
print(fibo(n))
