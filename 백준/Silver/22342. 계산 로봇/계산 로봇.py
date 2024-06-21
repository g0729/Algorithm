n, m = map(int, input().split())
MAP = [list(map(int, input().rstrip())) for _ in range(n)]
dp = [[0] * m for _ in range(n)]

for i in range(n):
    dp[i][0] = MAP[i][0]

for i in range(1, m - 1):
    for j in range(n):
        up = max(j - 1, 0)
        down = min(j + 1, n - 1)

        temp = 0
        for k in range(up, down + 1):
            temp = max(temp, dp[k][i - 1])

        dp[j][i] = temp + MAP[j][i]

answer = 0

for i in range(n):
    answer = max(answer, dp[i][m - 2])

print(answer)
