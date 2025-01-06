n, s, m = map(int, input().split())
v = list(map(int, input().split()))
dp = [[False] * (m + 1) for _ in range(51)]
dp[0][s] = True

for i in range(1, n + 1):

    for j in range(m + 1):
        if not dp[i - 1][j]:
            continue

        left, right = j - v[i - 1], j + v[i - 1]

        if left >= 0:
            dp[i][left] = True
        if right <= m:
            dp[i][right] = True


for i in range(m, -1, -1):
    if dp[n][i]:
        print(i)
        exit(0)

print(-1)
