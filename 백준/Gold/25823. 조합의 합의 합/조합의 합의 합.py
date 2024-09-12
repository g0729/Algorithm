def comb(p, q):
    return (factorial[p] * pow((factorial[p - q] * factorial[q]) % MOD, MOD - 2, MOD)) % MOD


n = int(input())
MOD = 1000000007
factorial = [1, 1, 2]

for i in range(3, 2 * n + 2):
    factorial.append(factorial[i - 1] * i % MOD)


res = 0

for i in range(3, n + 1):
    res = (res + comb(i * 2, i)) % MOD

print(res)
