def pow(base, exp):
    if exp == 0:
        return 1
    temp = pow(base, exp // 2)
    res = (temp * temp) % MOD

    if exp % 2 == 0:
        return res
    else:
        return (res * base) % MOD


n, r = map(int, input().split())
MOD = 1000000007
fac = [1, 1, 2]

for i in range(3, n + 1):
    fac.append((fac[-1] * i) % MOD)

answer = pow((fac[n - r] * fac[r]) % MOD, MOD - 2)
answer = (fac[n] * answer) % MOD
print(answer)
