from collections import defaultdict

n, m = map(int, input().split())
MOD = 1000000007
primes = defaultdict(int)

for i in range(2, int(n**0.5) + 1):
    while n % i == 0:
        primes[i] += 1
        n //= i
if n != 1:
    primes[n] = 1


def f(base, exp):
    return ((pow(base, exp + 1, MOD) - 1) * pow(base - 1, MOD - 2, MOD)) % MOD


res = 1
for key, value in primes.items():
    res = (res * f(key, value * m)) % MOD


print(res)
