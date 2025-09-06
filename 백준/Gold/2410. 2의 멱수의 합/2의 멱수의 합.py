import sys

input = sys.stdin.readline


def solve():
    n = int(input())

    dp = [0] * (n + 1)
    dp[0] = 1

    for i in range(1, n + 1):
        dp[i] = (dp[i - 1] + (dp[i // 2] if i % 2 == 0 else 0)) % 1000000000

    print(dp[n])


if __name__ == "__main__":
    solve()
