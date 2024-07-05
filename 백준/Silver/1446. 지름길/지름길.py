n, d = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(n)]
dp = [i for i in range(d + 1)]

for i in range(1, d + 1):
    for j in range(n):
        if edges[j][1] == i:
            dp[i] = min(dp[i], dp[edges[j][0]] + edges[j][2])
    dp[i] = min(dp[i - 1] + 1, dp[i])

print(dp[d])
