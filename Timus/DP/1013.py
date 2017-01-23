def matrix_square(A, mod):
    return mat_mult(A,A,mod)
def mat_mult(A,B, mod):
      if mod is not None:
          return [[(A[0][0]*B[0][0] + A[0][1]*B[1][0])%mod, (A[0][0]*B[0][1] + A[0][1]*B[1][1])%mod],
                      [(A[1][0]*B[0][0] + A[1][1]*B[1][0])%mod, (A[1][0]*B[0][1] + A[1][1]*B[1][1])%mod]]
def matrix_pow(M, power, mod):
    res = [[1 for col in xrange(2)]for row in xrange(2)]
    res[0][1] = 0
    res[1][0] = 0
    while( power > 0 ) :
        if(power % 2 == 1) :
            res = mat_mult(res , M , mod)
        M = mat_mult(M , M , mod)
        power = power / 2
    return res
n = int(input())
k = int(input())
mod = int(input())
T = [[k-1 for col in xrange(2)] for row in xrange(2)]
T[1][0] = 1
T[1][1] = 0
T = matrix_pow(T , n-1 , mod)
ans = (T[0][0] * (k-1)) % mod
ans = (ans + T[0][1]) % mod
print ans

