a, b, n = map(int, input().split())
MOD = 10**9 + 7
print(pow((1 << 31), n - 1, MOD))
