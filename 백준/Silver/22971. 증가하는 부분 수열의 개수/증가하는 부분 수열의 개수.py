import sys

input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
v = list(map(int, input().split()))
MOD = 998244353
dp = [0] * (n)
dp[0] = 1

for i in range(1, n):
    temp = 1
    for j in range(i):
        if v[i] > v[j]:
            temp = (temp + dp[j]) % MOD
    dp[i] = temp

print(" ".join(map(str, dp)))
