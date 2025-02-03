n = int(input())
w = list(map(int, input().split()))
m = int(input())
l = list(map(int, input().split()))
k = int(input())
dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
for i in range(1, n + 1):
    dp[i][0] = dp[i - 1][0] + w[i - 1]
for i in range(1, m + 1):
    if dp[0][i - 1] % k == 0:
        dp[0][i] = dp[0][i - 1] - l[i - 1]
    else:
        dp[0][i] = dp[0][i - 1] - min((dp[0][i - 1]) % k, l[i - 1])

for i in range(1, n + 1):
    for j in range(1, m + 1):
        if dp[i][j - 1] % k == 0:
            dp[i][j] = max(dp[i - 1][j] + w[i - 1], dp[i][j - 1] - l[j - 1])
        else:
            dp[i][j] = max(dp[i - 1][j] + w[i - 1], dp[i][j - 1] - min(l[j - 1], dp[i][j - 1] % k))

print(dp[n][m])
