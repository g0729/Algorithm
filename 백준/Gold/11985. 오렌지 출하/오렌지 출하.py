import sys

input = sys.stdin.readline

n, m, k = map(int, input().split())
v = [0] + [int(input()) for _ in range(n)]
dp = [0] * (n + 1)

dp[1] = k

for i in range(2, n + 1):
    dp[i] = dp[i - 1] + k

    max_val = 0
    min_val = int(1e12)
    for j in range(i, max(i - m, 0), -1):
        s = i - j + 1
        max_val = max(max_val, v[j])
        min_val = min(min_val, v[j])

        dp[i] = min(dp[i], dp[j - 1] + k + s * (max_val - min_val))

print(dp[n])
