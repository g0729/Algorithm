import sys

input = sys.stdin.readline


def solve():
    n = int(input())

    MOD = 10**9 + 7

    dp = [[0] * 5 for _ in range(n)]

    dp[0][0] = 25
    dp[0][1] = 1

    for i in range(1, n):
        dp[i][0] = (dp[i - 1][0] * 25) % MOD
        for j in range(1, 4):
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * 25) % MOD
        dp[i][4] = (dp[i - 1][3] + dp[i - 1][4] * 26) % MOD

    print(dp[n - 1][4])


if __name__ == "__main__":
    solve()
