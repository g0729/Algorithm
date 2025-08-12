import sys

input = sys.stdin.readline


def solve():
    h, w = map(int, input().split())
    b1 = [list(map(int, input().split())) for _ in range(h)]
    b2 = [list(map(int, input().split())) for _ in range(h)]
    dp = [[0] * w for _ in range(h)]

    for i in range(w):
        dp[0][i] = (b1[0][i] - b2[0][i]) ** 2

    for i in range(1, h):
        for j in range(w):
            dp[i][j] = (b1[i][j] - b2[i][j]) ** 2
            if w == 1:
                dp[i][j] += dp[i - 1][j]
                continue
            if j == 0:
                dp[i][j] += min(dp[i - 1][j], dp[i - 1][j + 1])
            elif j == w - 1:
                dp[i][j] += min(dp[i - 1][j], dp[i - 1][j - 1])
            else:
                dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1])

    print(min(dp[h - 1]))


if __name__ == "__main__":
    solve()
